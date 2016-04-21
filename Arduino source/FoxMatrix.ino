#include <Arduino.h>

/*Led matrix IoT controller
  128x10 (four 32x10 linked modules) led matrix display
  controlled with 4bit row select lines and 32bit line shift register.
  ESP8266 (ESP-12F module) as internet enabled application processor
  http://esp8266.github.io/Arduino/versions/2.1.0/doc/reference.html
  Ketturi 2016
*/

#include <pgmspace.h>
#include <SPI.h>
#include "bitmap.h" //Image data from kukkaconvert.exe by wuffe goes here, put in PROGMEM to save ram
#include "hardware.h" //Hardware definitions

//ESP8266 stuff
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h> //http://esp8266.github.io/Arduino/versions/2.1.0/doc/ota_updates/ota_updates.html

//WiFiManager
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> //https://github.com/tzapu/WiFiManager

#define ANIMATION true //animation or scrolling

byte pwm = 50; //sets initial brightness
const unsigned int rowOnTime = 1000; //how long one row is lit, uS
const unsigned int framerate = 5000; //milliseconds between frames, slows display down to readable speed
unsigned long previousMillis = 0;
int frame = 0;

void setup() { //Set pins to outputs and inits other stuff
  pinMode(16, SPECIAL); //Set GPIO16 to default function, controls reset

  //Important, do not remove these, or updating over wifi wont work!
  //*******************************
  setWiFi();   //Start WiFiManager
  otaUpdate(); //Enable ota updates
  //*******************************

  pinMode(0, FUNCTION_0);
  pinMode(1, FUNCTION_3);
  pinMode(2, FUNCTION_0);
  pinMode(3, FUNCTION_3);
  pinMode(4, FUNCTION_0);
  pinMode(5, FUNCTION_0);
  pinMode(13, FUNCTION_2);
  pinMode(14, FUNCTION_2);
  pinMode(15, FUNCTION_2);

  pinMode(latchPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);

  for (int i = 0; i < 4; i++) {
    pinMode(rowAdrsPin[i], OUTPUT);
  }

  analogWrite(pwmPin, pwm); //Set initial brightness
  SPI.begin();
  Serial.setDebugOutput(false); //Stop all serial communication as serial pins are used for display
  Serial.end();
}

void loop() { //loops constantly
  ArduinoOTA.handle(); //Checks for incoming update, please don't remove!
  refreshDisplay();
}

void refreshDisplay() { //Updates whole display
#if (ANIMATION) //shows single frames crating animation
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= framerate) { //crude timer for frame rate.
    previousMillis = currentMillis;
    if (frame < (imageWidth / ledColumns ))
      frame++;
    else
      frame = 0;
  }

  for (byte row = firstRowAdrs; row <= lastRowAdrs; row++) {  //Displaythingy happens here, select row, put column data in, change row, start again...
    selectRow(row);
    sendColumn(frame * ledColumns, row);
  }

#else //shows image that is scrolling from right to left
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= framerate) {
    previousMillis = currentMillis;
    if (frame < imageWidth)
      frame++;
    else
      frame = 0;
  }

  for (byte row = firstRowArds; row <= lastRowAdrs; row++) { //Displaythingy happens here, select row, put column data in, change row, start again...
    selectRow(row);
    sendColumn(frame, row);
  }
#endif
}

void sendColumn(int col, byte row) { //Toggles control lines and outputs display data.
  digitalWrite(latchPin, LOW);
  shiftOut32(getRowWord(col + 96, row, imageWidth, imageData)); //last panel
  shiftOut32(getRowWord(col + 64, row, imageWidth, imageData)); //third panel
  shiftOut32(getRowWord(col + 32, row, imageWidth, imageData)); //second panel
  shiftOut32(getRowWord(col , row, imageWidth, imageData));     //first panel
  digitalWrite(latchPin, HIGH);

  digitalWrite(enablePin, LOW);
  /*Delay for leds being enabled, affects how bright display is.
    ESP8266 does WiFi and TCP/IP task during delays*/
  delayMicroseconds(rowOnTime);
  digitalWrite(enablePin, HIGH);
}

void selectRow(byte RowAdrs) { //Selects which row gets illuminated, 4Bit address
  for (int b = 0; b < 4; b++) {
    if ((0x01 & RowAdrs) < 0x01)
      digitalWrite(rowAdrsPin[b], LOW);
    else
      digitalWrite(rowAdrsPin[b], HIGH);
    RowAdrs >>= 1;
  }
}

void shiftOut32(unsigned long input) { //32Bit shift out with HW SPI, sends data in 8bit pieces to shift register
  SPI.beginTransaction(SPISettings(SPISPEED, LSBFIRST, SPI_MODE0)); //25Mhz, LSBFIRST, clock polarity and phase
  SPI.transfer(input >> 0);
  SPI.transfer(input >> 8);
  SPI.transfer(input >> 16);
  SPI.transfer(input >> 24);
  SPI.endTransaction();
}

//getRowWord by wuffe, converts bitmap array to display lines
const unsigned long getRowWord(const unsigned int x, unsigned const int y, const unsigned int width, const unsigned long* data) {
  // NB: x's remainders may be slow to calculate, if compiler can't deduce beforehand
  // what value "width" will get when function is called.
  const unsigned int xa = x % width;
  const unsigned int xb = (x + 32) % width;
  const unsigned int ya = y % 12;
  const unsigned int shift = xa % 32;

  const unsigned int aPtr = ya + (xa / 32) * 12;
  const unsigned int bPtr = ya + (xb / 32) * 12;

  //Conditional to prevent 32-bit variable being shifted with 32 (not defined, not in C anyhow).
  return shift == 0 ? data[aPtr] : ((data[aPtr] << shift) | (data[bPtr] >> (32 - shift)));
  //return shift == 0 ? pgm_read_dword(data + aPtr) : ((pgm_read_dword(data + aPtr) << shift) | (pgm_read_dword(data + bPtr) >> (bits - shift)));
}

void otaUpdate() { //Handless over the air updating from Arduino IDE
  WiFi.mode(WIFI_STA);
  WiFi.begin();
  ArduinoOTA.setHostname("FoxMatrix");
  // ArduinoOTA.setPassword((const char *)"123"); //Sets password for ota update
  ArduinoOTA.begin();
}

void setWiFi() { //If no wifi AP is found, create one, and serve user a config page at http://192.168.4.1
  WiFiManager wifiManager;
  wifiManager.setTimeout(180);          //In 3 minutes continue normaly even if no wlan detected.
  wifiManager.autoConnect("FoxMatrix"); //Start WiFiManager with spesified AP name.
}
