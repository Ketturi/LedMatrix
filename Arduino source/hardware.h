/* 
 * Hardware definitions for LED matrix with ESP8266 ESP-12F host.
 * 
 */

//Shift register pins
#define latchPin  15  //SS/CS- SPI Chip Select
#define clockPin  14  //SCLK   SPI Clock
#define dataPin   13  //MOSI   SPI Data out
#define enablePin  4  //Enables output driver when low, prevents ghosting while data is loaded
#define pwmPin     5  //for led driver current control, 255 gives 2A/panel!

const int multiplexPin[] = {0, 1, 2, 3}; //Row decoder pins, 0-11 dec values corresponds lines, 1-10 usable as 0 and 11 lines are missing all leds


