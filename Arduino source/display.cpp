/*
  Glue library for Adafruit GFX library.
  Implements functions between display hardware and graphics library.

  This is highly customized for spesific type of led matrix display
  and for esp8266.
  Ketturi Fox 2017
*/

#include "display.h"
#include <pgmspace.h>
#include <SPI.h>
#include "hardware.h"

#ifndef _swap_int16_t
#define _swap_int16_t(a, b) { int16_t t = a; a = b; b = t; }
#endif

#include <Fonts/FreeMono9pt7b.h>

void FoxMatrix::init(uint8_t rows, uint8_t width,  boolean dbuf) {
  // Allocate and initialize matrix buffer, 8bit word compressed
  int buffsize  = (DISPLAYWIDTH / 8 * DISPLAYHEIGHT),
      allocsize = (dbuf == true) ? (buffsize * 2) : buffsize;

  if (NULL == (matrixbuff[0] = (uint8_t *)malloc(allocsize))) return;
  memset(matrixbuff[0], 0, allocsize);

  // If not double-buffered, both buffers then point to the same address:
  matrixbuff[1] = (dbuf == true) ? &matrixbuff[0][buffsize] : matrixbuff[0];

  row = DISPLAYHEIGHT; //set to DISPLAYHEIGHT - 1 if 12 row display! 10 row display starts from addrs 1
  swapflag = false;
  backindex = 0; // Array index of back buffer
}

//inits Adafruit_GFX library
FoxMatrix::FoxMatrix(uint8_t rows,  uint8_t width, boolean dbuf) :
  Adafruit_GFX(width, rows) {
  init(rows, width, dbuf);
}

void FoxMatrix::begin(void) {
  backindex = 0; // Back buffer
  buffptr     = matrixbuff[1 - backindex]; // -> front buffer
  memset(matrixbuff[backindex], 0x00, (DISPLAYWIDTH / 8 * DISPLAYHEIGHT)); //Fill buffer with zeros

  //Hardcoded stuff, ESP8266 pins not swappable anyway due function constrictions
  pinMode(0, FUNCTION_0);  //GPIO Row address line 0
  pinMode(1, FUNCTION_3);  //GPIO Row address line 1
  pinMode(2, FUNCTION_0);  //GPIO Row address line 2
  pinMode(3, FUNCTION_3);  //GPIO Row address line 3
  pinMode(4, FUNCTION_0);  //GPIO Output enable
  pinMode(5, FUNCTION_0);  //PWM Display current drive
  pinMode(13, FUNCTION_2); //SPI Data out
  pinMode(14, FUNCTION_2); //SPI Clock
  pinMode(15, FUNCTION_2); //SPI Chip Select

  pinMode(latchPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);
  for (int i = 0; i < 4; i++) {
    pinMode(rowAdrsPin[i], OUTPUT);
  }

  //Set initial pwm output, and init SPI
  analogWrite(pwmPin, pwm);
  SPI.setHwCs(true);
  SPI.begin();

  Serial.setDebugOutput(false); //Stop all serial communication as serial pins are used for display
  Serial.end(); //Make sure serial is not used, interferes badly with display

  //Debug, shows panel ID on row 1, not flexible with panel count
  GPOC = (1 << enablePin);
  shiftOut32(1);
  shiftOut32(3);
  shiftOut32(7);
  shiftOut32(15);
  selectRow(1);
  delay(100);
}

//matrixbuff[backindex] needs to be filled with x and y stuff. Adafruit_GFX uses drawPixel for all graphics drawing!
//https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GFX.h
void FoxMatrix::drawPixel(int16_t x, int16_t y, uint16_t c) {
  uint8_t *ptr;

  //Checks that pixels end up within display area
  if ((x < 0) || (x >= _width) || (y < 0) || (y >= _height)) return;

  //rotation, not usefull on this display.
  switch (rotation) {
    case 1:
      _swap_int16_t(x, y);
      x = WIDTH - 1 - x;
      break;
    case 2:
      x = WIDTH - 1 - x;
      y = HEIGHT - 1 - y;
      break;
    case 3:
      _swap_int16_t(x, y);
      y = HEIGHT - 1 - y ;
      break;
  }

  //Sets display buffer with either zero or one pixel
  //Data is compressed to 8bit words.
  if (c) {
    //Displaybuffer       Baseaddress                      8Bit with pixel mask     
    matrixbuff[backindex][(x + y * DISPLAYWIDTH) / 8 ] |= (1 << (7 - (x % 8))); //set (x,y)
  }
  else {
    matrixbuff[backindex][(x + y * DISPLAYWIDTH) / 8] &= ~(1 << (7 - (x % 8))); //clear (x,y)
  }
}

//Sets whole display buffer either one or zero
void FoxMatrix::fillScreen(uint8_t c) {
  if (c == 1) {
    memset(matrixbuff[backindex], 0xFF, ((DISPLAYWIDTH / 8) * DISPLAYHEIGHT));
  }
  else        {
    memset(matrixbuff[backindex], 0x00, ((DISPLAYWIDTH / 8)* DISPLAYHEIGHT));
  }
}

// For smooth animation -- drawing always takes place in the "back" buffer;
// this method pushes it to the "front" for display.  Passing "true", the
// updated display contents are then copied to the new back buffer and can
// be incrementally modified.  If "false", the back buffer then contains
// the old front buffer contents -- your code can either clear this or
// draw over every pixel.  (No effect if double-buffering is not enabled.)
void FoxMatrix::swapBuffers(boolean copy) {
  if (matrixbuff[0] != matrixbuff[1]) {
    // To avoid 'tearing' display, actual swap takes place in the interrupt
    // handler, at the end of a complete screen refresh cycle.
    swapflag = true;                  // Set flag here, then...
    while (swapflag == true) delay(1); // wait for interrupt to clear it
    if (copy == true)
      memcpy(matrixbuff[backindex], matrixbuff[1 - backindex], DISPLAYWIDTH * DISPLAYHEIGHT);
  }
}

// Return address of back buffer -- can then load/store data directly
uint8_t *FoxMatrix::backBuffer() {
  return matrixbuff[backindex];
}

//Needs interrupt for constant frame rate!
void ICACHE_RAM_ATTR FoxMatrix::updateDisplay(void) {
  uint8_t *ptr;

  if (row >= lastRowAdrs) {       // Check if all rows are displayed
    if (swapflag == true) {   // Swap front/back buffers if requested
      backindex = 1 - backindex;
      swapflag  = false;
    }
    buffptr = matrixbuff[1 - backindex]; // Reset into front buffer*/
  }

  //Goes trough all display lines
  for (row = 0; row <= lastRowAdrs; row++) {
    selectRow(row + firstRowAdrs); //Selects row to be displayed

    // buffptr, being 'volatile' type, doesn't take well to optimization.
    // A local register copy can speed some things up:
    ptr = (uint8_t *)buffptr;


    uint8_t *rowptr = ptr + (DISPLAYWIDTH * row) / 8; //Gets data from display buffer in 8bit packets

    //Converts 8bit packets to 32bit*panels and outputs it to pixel drivers
    for (int block = DISPLAYWIDTH / 32 - 1; block >= 0; block--) {
      uint32_t scanline = rowptr[block * 4 + 0] << 24 | rowptr[block * 4 + 1] << 16 | rowptr[block * 4 + 2] << 8 | rowptr[block * 4 + 3];
      shiftOut32(scanline);
    }

    GPOC = (1 << enablePin); //Set pixel driver output on
    /*Delay for leds being enabled, affects how bright display is.
      Would be better with interupts but delay seems to be working!*/
    delayMicroseconds(rowOnTime);
    GPOS = (1 << enablePin); //Set pixel driver output off, removes ghosting durign update
  }
}

void FoxMatrix::setBrightness(uint8_t b) {
  analogWrite(pwmPin, b);
}

//------ Utility functions for updateDisplay -----

//Simple parallel output. Optimized with GPIO register control!
void ICACHE_RAM_ATTR FoxMatrix::selectRow(byte RowAdrs) { //Selects which row gets illuminated, 4Bit address
  if (RowAdrs & 0x1) GPOS = (1 << rowAdrsPin[0]);
  else               GPOC = (1 << rowAdrsPin[0]);
  if (RowAdrs & 0x2) GPOS = (1 << rowAdrsPin[1]);
  else               GPOC = (1 << rowAdrsPin[1]);
  if (RowAdrs & 0x4) GPOS = (1 << rowAdrsPin[2]);
  else               GPOC = (1 << rowAdrsPin[2]);
  if (RowAdrs & 0x8) GPOS = (1 << rowAdrsPin[3]);
  else               GPOC = (1 << rowAdrsPin[3]);
}

//https://github.com/esp8266/Arduino/blob/master/libraries/SPI/SPI.h Use spi.write32() and setHwCs(true)!
void ICACHE_RAM_ATTR FoxMatrix::shiftOut32(uint32_t input) { //32Bit shift out with HW SPI, sends data in 8bit pieces to shift register
  SPI.beginTransaction(SPISettings(SPISPEED, LSBFIRST, SPI_MODE0)); //25Mhz, LSBFIRST, clock polarity and phase
  SPI.write32(input); //Could this be implemented with DMA/memcopy?
  SPI.endTransaction();
}


