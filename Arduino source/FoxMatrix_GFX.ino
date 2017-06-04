/*Led matrix IoT controller
  128x10 (four 32x10 linked modules) led matrix display
  controlled with 4bit row select lines and 32bit line shift register.
  ESP8266 (ESP-12F module) as internet enabled application processor
  http://esp8266.github.io/Arduino/versions/2.1.0/doc/reference.html
  Ketturi 2016
*/

#include <Arduino.h>
extern "C" {
#include "user_interface.h"
}
#include <Adafruit_GFX.h>
#include "display.h" //FoxMatrix LED display library

//Font for display
#include "FoxFont.h"
#define font &FoxFont
#define textPos 9 //Vertical position for font

//Bitmaps for symbols
#include "Bitmaps.h"

//Configure display
FoxMatrix screen(10, 128, false); //(height, width, double_buffering)

//Interrupt for display refresh, needs to be polled often
os_timer_t updateTimer;
void ICACHE_RAM_ATTR INT_handler(void *pArg) {
  screen.updateDisplay();
}

#include <Ticker.h> //Ticker for scheduling display stuff
Ticker scheduler;
Ticker busupdater;
Ticker message;

int count = 0;
int page = 0;
bool msgWait = false;
int lastpage = 4;
int pageDelay = 10; //Seconds between display page changes

//NTP time
#define NTP_ADDRS "172.20.1.1" //Local NTP server, it's polled quite often so public NTP is not to be used if possible
#include <TimeLib.h>
#include <NtpClientLib.h>

#include "wifi_handler.h"
#include "busstop.h"

BusStop koskipuisto("0501"); //Calls TKL api and sets monitored stop.

void setup() {
  pinMode(16, SPECIAL); //Set GPIO16 to default function, controls reset

  screen.begin(); //Starts display routine

  screen.selectRow(2); //Debug, tells that display is initialized
  delay(100);

  screen.fillScreen(0); //Empty buffer

  os_timer_setfn(&updateTimer, INT_handler, NULL); //set sw timer interupt callback
  os_timer_arm(&updateTimer, 2, true); //Start timer, at this time display starts to show data from framebuffer

  screen.setTextWrap(false);
  screen.setTextSize(1);
  screen.setFont(font);
  screen.setTextColor(1);
  screen.setCursor(0, textPos);
  screen.print("ESP8266 WifiDisplay");
  delay(1000);

  //Wifi
  WiFi.persistent(true);
  setWiFi(); //Starts wifi routines
  wificallbacks(); //Enables wifi messages to display
  otaUpdate(); //Enable ota updates

  NTP.begin(NTP_ADDRS, 1, true); //Initializes NTP connection
  NTP.setInterval(600); //Update NTP time every 10 minutes (ESP8266 is inaccurate at timekeeping)
  NTP.setDayLight(true);
  ntpCallback(); //Enables NTP messages on screen

  screen.setCursor(0, textPos);
  scheduler.attach(10, changePage);
  busupdater.attach(60, updateBusData);
  koskipuisto.updateBuffer();
}

void loop() { //loops constantly
  ArduinoOTA.handle();

  while ( WiFi.status() == WL_CONNECTED) {
    if (msgWait == false) {
      switch (page) {
        case 0:
          screen.fillScreen(0);
          screen.drawBitmap(0, 0, BitmapInfo, 16, 10, 1);
          screen.setCursor(12, textPos);
          screen.print("Fox Matrix");
          break;
        case 1:
          screen.fillScreen(0);
          screen.drawBitmap(0, 0, BitmapBus, 16, 10, 1);
          screen.setCursor(12, textPos);
          screen.print(koskipuisto.returnLine(0));
          screen.print(" ");
          screen.print(koskipuisto.returnTime(0));
          break;
        case 4:
          screen.fillScreen(0);
          screen.drawBitmap(0, 0, BitmapClock, 16, 10, 1);
          screen.setCursor(12, textPos);
          screen.print(NTP.getTimeStr());
          screen.drawBitmap(54, 0, BitmapCalendar, 16, 10, 1);
          screen.setCursor(66, textPos);
          screen.print(NTP.getDateStr());
          break;
      }

      screen.swapBuffers(false); //Bring backbuffer to display
      yield(); //Run background functions
    }
  }
  screen.swapBuffers(false); //Bring backbuffer to display
  yield();
}

void ntpCallback() {
  NTP.onNTPSyncEvent([](NTPSyncEvent_t ntpEvent) {
    if (ntpEvent) {
      msgWait = true;
      screen.fillScreen(0);
      screen.drawBitmap(0, 0, BitmapWarn, 16, 10, 1);
      screen.setCursor(12, textPos);
      screen.print("NTP error: ");
      if (ntpEvent == noResponse)
        screen.print("Server not reachable");
      else if (ntpEvent == invalidAddress)
        screen.print("Invalid address");
    }
    else {
    }
  });
}

void changePage() {
  if (msgWait == false) {
    if (page == lastpage)
      page = 0;
    else
      page++;
  }
  else {
    scheduler.detach();
    msgWait == false;
    message.once(5, startScheduler);
  }
}

void updateBusData() {
  koskipuisto.updateBuffer(); //Downloads lastest stuff
}

void startScheduler() {
  scheduler.attach(pageDelay, changePage);
}

