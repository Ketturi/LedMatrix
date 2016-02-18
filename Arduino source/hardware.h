/* 
 * Hardware definitions for LED matrix.
 */

//Shift register pins
#define latchPin  10  //SS/SC- SPI Chip Select
#define clockPin  14  //SCLK   SPI Clock
#define dataPin   16   //MOSI   SPI Data out
#define enablePin  9 //Enables output driver when low, prevents ghosting while data is loaded
#define pwmPin     5 //for led driver current control, 255 gives 2A/panel!

const int multiplexPin[] = {3, 2, 0, 1}; //Row decoder pins, 0-11 dec values corresponds lines, 1-10 usable as 0 and 11 lines are missing all leds

