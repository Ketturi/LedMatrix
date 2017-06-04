/*
  Glue library for Adafruit GFX library.
  Implements functions between display hardware and graphics library.

  This is highly customized for spesific type of led matrix display
  and for esp8266.
  Ketturi Fox 2017
*/

#include <Arduino.h>
#include <Adafruit_GFX.h>

class FoxMatrix : public Adafruit_GFX { //https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GFX.h

  public:
    FoxMatrix(uint8_t rows,  uint8_t width, boolean dbuf);


    void    begin(void), //initialisez display driver
            setBrightness(uint8_t b), //Modify brightness by current drive
            drawPixel(int16_t x, int16_t y, uint16_t c), //Sets pixels on frame buffer
            fillScreen(uint8_t c), //Swaps all pixels in display buffer
            updateDisplay(void), //Sends one frame from framebuffer to display hardware, needs to be constantly called due multiplexing
            swapBuffers(boolean copy); //Switches which buffer is used for drawing in double buffered mode

    uint8_t *backBuffer(void); //Returns currently active double buffer

    //internal display driving functions
    void    selectRow(byte RowAddrs),
            shiftOut32(uint32_t input);

  private:
    uint8_t *matrixbuff[2]; //framebuffer memory pointer
    volatile uint8_t backindex;
    volatile boolean swapflag;
  
    //Init/alloc
    void init(uint8_t rows,  uint8_t width, boolean dbuf);

    //counterspointers
    volatile uint8_t row;
    volatile uint8_t *buffptr;
};

