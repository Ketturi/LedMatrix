/*Led matrix controller
 * 128x10 ((32x10)x4) led matrix
 * controlled with 4bit row select lines and 32bit line shift register
 * Ketturi 2016
 */

#include <avr/pgmspace.h>
#include <SPI.h>
#include "bitmap.h" //image data from kukkaconvert.exe by wuffe goes here, put in PROGMEM to save ram
#include "hardware.h"
#define ANIMATION true //animation or scrolling

byte pwm = 150; //sets initial brightness
const unsigned int rowOnTime = 900; //how long one row is lit

const unsigned int bits = 32; //Bit count for getRowWord function, 32 bits default, don't change
const unsigned int framerate = 256; //exponent of 2, slows display down, as it runs around 140fps

void setup() { //Set pins to outputs and inits other stuff
  pinMode(latchPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);

  for (int i = 0; i < 4; i++) {
    pinMode(multiplexPin[i], OUTPUT);
  }
  
  Serial.begin(9600);
  analogWrite(pwmPin, pwm);
  SPI.begin();
}

void loop() {
  setBrightness(); //set brightness from serial port input, for testing purposes

#if (ANIMATION)
  for (int frame = 0; frame < (imageWidth / 128)*framerate; frame++) { //main loop, that throws image data frame by frame, row by row
    for (byte row = 1; row <= 10; row++) {                          //Displaythingy happens here, select row, put column data in, change row, start again...
      multiplexRow(row);
      refreshDisplay((frame / framerate) * 128, row);
    }
  }
#else
  for (int frame = 0; frame < imageWidth * framerate; frame++) {
    for (byte row = 1; row <= 10; row++) { //Displaythingy happens here, select row, put column data in, change row, start again...
      multiplexRow(row);
      refreshDisplay(frame / framerate, row);
    }
  }
#endif
}


void refreshDisplay(int col, byte row) {
  digitalWrite(latchPin, LOW);
  shiftOut32(getRowWord(col + 96, row, imageWidth, imageData)); //last panel
  shiftOut32(getRowWord(col + 64, row, imageWidth, imageData)); //third panel
  shiftOut32(getRowWord(col + 32, row, imageWidth, imageData)); //second panel
  shiftOut32(getRowWord(col , row, imageWidth, imageData));     //first panel
  digitalWrite(latchPin, HIGH);

  digitalWrite(enablePin, LOW);
  /*Delay for display being on, affects how bright display is. Something smart with interrupts could be done here.
  * This is kinda critical as stuck leds may burn out at high brightness. Some kind of watchdoge to prevent this?
  */
  delayMicroseconds(rowOnTime);
  digitalWrite(enablePin, HIGH);
}

void multiplexRow(byte multiRow) { //Selects which row gets illuminated, 0-11 in four bits, 1-10 usable as display
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

void setBrightness() {
  while (Serial.available() > 0) { //Reads serial port and sets pwm value
    int pwm = Serial.parseInt();
    if (Serial.read() == '\n') {
      Serial.print("PWM is set at "); Serial.println(pwm);
      analogWrite(pwmPin, pwm);
    }
  }
}

void shiftOut32(unsigned long input) { //32Bit shift out, sends data in 8bit pieces to shift register, LSBFIRST
  SPI.beginTransaction(SPISettings(20000000, LSBFIRST, SPI_MODE0));
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
  const unsigned int xb = (x + bits) % width;
  const unsigned int ya = y % 12;
  const unsigned int shift = xa % bits;

  const unsigned int aPtr = ya + (xa / bits) * 12;
  const unsigned int bPtr = ya + (xb / bits) * 12;

  // Konditionaali, ettei tulisi shiftattua 32:lla 32-bittistä muuttujaa (ei määritelty, ainakaan C:ssä).
  // return shift == 0 ? data[aPtr] : ((data[aPtr] << shift) | (data[bPtr] >> (bits - shift)));
  return shift == 0 ? pgm_read_dword(data + aPtr) : ((pgm_read_dword(data + aPtr) << shift) | (pgm_read_dword(data + bPtr) >> (bits - shift)));
}