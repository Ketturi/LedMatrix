/*Led matrix controller
 * 128x10 ((32x10)x4) led matrix
 * controlled with 4bit row select lines and 32bit line shift register.
 * ESP8266 (ESP12F module) as MCU, source code in arduino ide sketch.
 * Ketturi 2016
 */

#include <pgmspace.h>
#include <SPI.h>
#include "bitmap.h" //image data from kukkaconvert.exe by wuffe goes here, put in PROGMEM to save ram
#include "hardware.h" //hardware definitions

//ESP8266 wifi stuff
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
const char* ssid = "Kettuluola";      //wifi credientials for ota update
const char* password = "ketturiturri";

#define ANIMATION true //animation or scrolling

byte pwm = 5; //sets initial brightness
const unsigned int rowOnTime = 1000; //how long one row is lit, given as microseconds
const unsigned int framerate = 5000; //milliseconds between frames, slows display down, as it runs really fast
unsigned long previousMillis = 0;
int frame = 0;

void setup() { //Set pins to outputs and inits other stuff
  pinMode(16, SPECIAL); //Set GPIO16 to default function, is tied to reset for reseting chip.
  otaUpdate(); //Enable ota updates
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
    pinMode(multiplexPin[i], OUTPUT);
  }

  analogWrite(pwmPin, pwm);
  SPI.begin();
  Serial.setDebugOutput(0); //Stop all serial communication as serial pins are used for display
  Serial.end(); //STOP!!! No serial!
}

void loop() {
  ArduinoOTA.handle(); //Check network for incoming update

#if (ANIMATION) //frame is actually 1 column, so divided by 128 for whole display in animation
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= framerate) { //
    previousMillis = currentMillis;
    if (frame < (imageWidth / 128 )) {
      frame++;
    }
    else {
      frame = 0;
    }
  }

  for (byte row = 1; row <= 10; row++) {  //Displaythingy happens here, select row, put column data in, change row, start again...
    multiplexRow(row);
    refreshDisplay(frame * 128, row);
  }

#else //frame is one column! so frame=1 row=1 is the first led in top left!
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= framerate) {  //nonhooking slowdown made from duct tape
    previousMillis = currentMillis;
    if (frame < imageWidth) {
      frame++;
    }
    else {
      frame = 0;
    }
  }

  for (byte row = 1; row <= 10; row++) { //Displaythingy happens here, select row, put column data in, change row, start again...
    multiplexRow(row);
    refreshDisplay(frame, row);
  }

#endif
}


void refreshDisplay(int col, byte row) { //puts one horizontal line of serial data to display
  //digitalWrite(latchPin, LOW); //actually, spi seems to handle latch by itself
  shiftOut32(getRowWord(col + 96, row, imageWidth, imageData)); //last panel
  shiftOut32(getRowWord(col + 64, row, imageWidth, imageData)); //third panel
  shiftOut32(getRowWord(col + 32, row, imageWidth, imageData)); //second panel
  shiftOut32(getRowWord(col , row, imageWidth, imageData));     //first panel
  //digitalWrite(latchPin, HIGH);

  digitalWrite(enablePin, LOW);
  /*Delay for display being on, affects how bright display is. Something smart with interrupts could be done here.
  * This is kinda critical as stuck leds may burn out at high brightness. Some kind of watchdoge to prevent this?
  */
  delayMicroseconds(rowOnTime);
  digitalWrite(enablePin, HIGH);
}

void multiplexRow(byte multiRow) { //Selects which row gets illuminated, 0-11 in four bits, 1-10 usable display area
  for (int b = 0; b < 4; b++) {
    if ((0x01 & multiRow) < 0x01) {
      digitalWrite(multiplexPin[b], LOW);
    }
    else {
      digitalWrite(multiplexPin[b], HIGH);
    }
    multiRow >>= 1;
  }
}

void shiftOut32(unsigned long input) { //32Bit shift out, sends data in 8bit pieces to shift register, LSBFIRST
  SPI.beginTransaction(SPISettings(25000000, LSBFIRST, SPI_MODE0));
  SPI.transfer(input >> 0);
  SPI.transfer(input >> 8);
  SPI.transfer(input >> 16);
  SPI.transfer(input >> 24);
  SPI.endTransaction();
}

const unsigned long getRowWord(const unsigned int x, unsigned const int y, const unsigned int width, const unsigned long* data) {  //getRowWord by wuffe, all cool stuff happens here
  // Huomaa että x:n jakojäännökset saattavat olla hitaita, jos kääntäjä ei pysty mitenkään
  // kääntäessä ennalta päättelemään, minkä arvon width saa funktiota kutsuttaessa.
  const unsigned int xa = x % width;
  const unsigned int xb = (x + 32) % width;
  const unsigned int ya = y % 12;
  const unsigned int shift = xa % 32;

  const unsigned int aPtr = ya + (xa / 32) * 12;
  const unsigned int bPtr = ya + (xb / 32) * 12;

  // Konditionaali, ettei tulisi shiftattua 32:lla 32-bittistä muuttujaa (ei määritelty, ainakaan C:ssä).
  return shift == 0 ? data[aPtr] : ((data[aPtr] << shift) | (data[bPtr] >> (32 - shift)));
}

void otaUpdate() {  //Connects to wifi network and sets over the air update
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
   
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {  //reset if connection can't be made
   delay(5000);
   ESP.restart();
  }

  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
   ArduinoOTA.setHostname("FoxMatrix");

  // No authentication by default
  // ArduinoOTA.setPassword((const char *)"123");
  ArduinoOTA.begin();
}
