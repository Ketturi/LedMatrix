#include <Arduino.h>
#include <Adafruit_GFX.h>

class FoxMatrix : public Adafruit_GFX { //https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GFX.h

  public:
    FoxMatrix(uint8_t rows,  uint8_t width, boolean dbuf);


    void    begin(void),
            setBrightness(uint8_t b),
            drawPixel(int16_t x, int16_t y, uint16_t c),
            fillScreen(uint8_t c),
            updateDisplay(void),
            swapBuffers(boolean copy);

    uint8_t *backBuffer(void);

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

