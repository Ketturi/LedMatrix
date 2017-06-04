/*
  WiFi and network functions for ESP8266
  
  Ketturi Fox 2017
*/

#include <ArduinoOTA.h> //http://esp8266.github.io/Arduino/versions/2.1.0/doc/ota_updates/ota_updates.html
//ESP8266 libbraries
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

WiFiEventHandler gotIpEventHandler, disconnectedEventHandler, connectedHandler, dhcpTimeoutHandler;

//WiFiManager
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> //https://github.com/tzapu/WiFiManager

void otaUpdate(void),
     configModeCallback (WiFiManager * myWiFiManager),
     setWiFi(void),
     wificallbacks(void);


void otaUpdate() { //Handless over the air updating from Arduino IDE
  ArduinoOTA.setHostname("FoxMatrix");
  // ArduinoOTA.setPassword((const char *)"123"); //Sets password for ota update
  ArduinoOTA.begin();
}

void configModeCallback (WiFiManager * myWiFiManager) {
  msgWait = true;
  screen.fillScreen(0);
  screen.drawBitmap(0, 0, BitmapWifiOn, 16, 10, 1);
  screen.setCursor(12, textPos);
  screen.print(myWiFiManager->getConfigPortalSSID());
  screen.print(": ");
  screen.print(WiFi.softAPIP());
}

void setWiFi() { //If no wifi AP is found, create one, and serve user a config page at http://192.168.4.1
  WiFiManager wifiManager;
  //wifiManager.resetSettings();
  wifiManager.setAPCallback(configModeCallback);
  //wifiManager.setTimeout(120);          //In 3 minutes continue normaly even if no wlan detected.
  //wifiManager.autoConnect("FoxMatrix"); //Start WiFiManager with spesified AP name.
  //WiFi.mode(WIFI_STA);
  // WiFi.begin();
  if (!wifiManager.autoConnect("FoxMatrix")) {
    screen.fillScreen(0);
    screen.drawBitmap(0, 0, BitmapWifiOff, 16, 10, 1);
    screen.setCursor(12, textPos);
    screen.print("Connection timeout");
    //reset and try again, or maybe put it to deep sleep
    delay(1000);
    ESP.reset();
  }
}

void wificallbacks(void) {
  connectedHandler = WiFi.onStationModeConnected([](const WiFiEventStationModeConnected & event)
  {
    msgWait = true;
    screen.fillScreen(0);
    screen.drawBitmap(0, 0, BitmapAP, 16, 10, 1);
    screen.setCursor(12, textPos);
    //screen.print("WiFi: ");
    screen.print(WiFi.SSID());
  });
  disconnectedEventHandler = WiFi.onStationModeDisconnected([](const WiFiEventStationModeDisconnected & event)
  {
    msgWait = true;
    screen.fillScreen(0);
    screen.drawBitmap(0, 0, BitmapWifiOff, 16, 10, 1);
    screen.setCursor(12, textPos);
    screen.print("No WiFi found");
  });
  gotIpEventHandler = WiFi.onStationModeGotIP([](const WiFiEventStationModeGotIP & event)
  {
    msgWait = true;
    screen.fillScreen(0);
    screen.drawBitmap(0, 0, BitmapIP, 16, 10, 1);
    screen.setCursor(12, textPos);
    //screen.print("IP: ");
    screen.print(WiFi.localIP());
  });
}

