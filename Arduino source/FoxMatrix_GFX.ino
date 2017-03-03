#include <Arduino.h>
extern "C" {
#include "user_interface.h"
}
#include <Adafruit_GFX.h>
#include "display.h" //FoxMatrix LED display library

#define textPos 2 //Vertical position for font

//#include <Fonts/FreeMono9pt7b.h>
//#include <Fonts/FreeSans9pt7b.h> //Wont fit display!
//#include "OpenSans6p.h"

//#define font FreeMono9pt7b

/*Led matrix IoT controller
  128x10 (four 32x10 linked modules) led matrix display
  controlled with 4bit row select lines and 32bit line shift register.
  ESP8266 (ESP-12F module) as internet enabled application processor
  http://esp8266.github.io/Arduino/versions/2.1.0/doc/reference.html
  Ketturi 2016
*/

//ESP8266 libbraries
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h> //http://esp8266.github.io/Arduino/versions/2.1.0/doc/ota_updates/ota_updates.html

WiFiEventHandler gotIpEventHandler, disconnectedEventHandler, connectedHandler, dhcpTimeoutHandler;

//WiFiManager
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> //https://github.com/tzapu/WiFiManager

//IoT
#include <ThingerSmartConfig.h>
//#include "thingerio.h"
//ThingerSmartConfig dispmatrix(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

//screen config
FoxMatrix screen(10, 128, false);

//Interrupt for display refresh, needs to be polled often
os_timer_t updateTimer;
void ICACHE_RAM_ATTR INT_handler(void *pArg) {
  screen.updateDisplay();
}

void setup() {
  pinMode(16, SPECIAL); //Set GPIO16 to default function, controls reset

  //Important, do not remove these, or updating over wifi wont work!
  //*******************************
  //setWiFi();   //Start WiFiManager
  //otaUpdate(); //Enable ota updates
  //*******************************
  screen.begin(); //Starts display routine

  screen.selectRow(2); //Debug, tells that display is initialized
  delay(100);

  screen.fillScreen(0); //Empty buffer

  os_timer_setfn(&updateTimer, INT_handler, NULL); //set sw timer interupt callback
  os_timer_arm(&updateTimer, 2, true); //Start timer, at this time display starts to show data from framebuffer


  screen.setTextWrap(false);
  //screen.setTextSize(1);
  //screen.setFont(font);
  screen.setTextColor(1);
  screen.setCursor(0, textPos);
  //screen.drawLine(0,0,127,0,1);
  screen.print("ESP8266 WifiDisplay");
  //screen.drawLine(0,9,127,9,1);

  //Wifi
  WiFi.persistent(false);
  WiFi.begin("FoxWLAN2.4G", "turripurri");
  connectedHandler = WiFi.onStationModeConnected([](const WiFiEventStationModeConnected & event)
  {
    screen.fillScreen(0);
    screen.setCursor(0, textPos);
    screen.print("WiFi: ");
    screen.print(WiFi.SSID());
  });
  disconnectedEventHandler = WiFi.onStationModeDisconnected([](const WiFiEventStationModeDisconnected & event)
  {
    screen.fillScreen(0);
    screen.setCursor(0, textPos);
    screen.print("WiFi Disconnected:");
  });
  gotIpEventHandler = WiFi.onStationModeGotIP([](const WiFiEventStationModeGotIP & event)
  {
    screen.fillScreen(0);
    screen.setCursor(0, textPos);
    screen.print("IP: ");
    screen.print(WiFi.localIP());
  });

  screen.setCursor(0, textPos);
}

void loop() { //loops constantly
  //Updates display on double buffered mode
  screen.swapBuffers(false); //Bring backbuffer to display
  yield(); //Run background functions
}


void otaUpdate() { //Handless over the air updating from Arduino IDE
  ArduinoOTA.setHostname("FoxMatrix");
  // ArduinoOTA.setPassword((const char *)"123"); //Sets password for ota update
  ArduinoOTA.begin();
}

void setWiFi() { //If no wifi AP is found, create one, and serve user a config page at http://192.168.4.1
  WiFiManager wifiManager;
  wifiManager.setAPCallback(configModeCallback);
  wifiManager.setTimeout(60);          //In 3 minutes continue normaly even if no wlan detected.
  wifiManager.autoConnect("FoxMatrix"); //Start WiFiManager with spesified AP name.
  WiFi.mode(WIFI_STA);
  WiFi.begin();
}

void configModeCallback (WiFiManager * myWiFiManager) {
  screen.fillScreen(0);
  screen.setCursor(0, textPos);
  screen.print("conf mode:");
  screen.print(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  //screen.print(myWiFiManager->getConfigPortalSSID());
  delay(100);
}

