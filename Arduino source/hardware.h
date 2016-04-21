/*
   Hardware definitions for LED matrix with ESP8266 ESP-12F target.
   http://www.electrodragon.com/w/ESP-12F_ESP8266_Wifi_Board
   https://github.com/Ketturi/LedMatrix/tree/master/Hardware
*/

/*ArduinoIDE settings:
   Board: "Generic ESP8266 Module" //Install board from http://github.com/esp8266/Arduino
   Flash Mode: "QIO"               //Selects how flash is controlled, QIO = 4 data lines
   Flash Size: 4M (1M SPIFFS)"     //4MB flash IC, 1M file system (3MB for scetch&OTA)
   Debug port: "Disabled"          //Disables serial debug, serial lines used for data lines
   Debug level: "None"             //No debuging
   Reset Method: "ck"              //Does not matter, no serial programming reset ability
   Flash Frequency: "40Mhz"        //Probably 40Mhz, 80Mhz should be carefully tested
   Upload Using: "OTA"             //Updated over network
   CPU Frequency: "160Mhz"         //Speed boost for faster display
   Upload SPEED: "115200"          //Does not matter when using OTA
   Port: "FoxMatrix at <ip> (Generic ESP8266 Module) //Select device from network, shows only when properly connected and discovered
*/

//Shift register pins
#define latchPin  15  //SS/CS  SPI Chip Select
#define clockPin  14  //SCLK   SPI Clock
#define dataPin   13  //MOSI   SPI Data out
#define enablePin  4  //OE     Enables output driver when low, prevents ghosting while data is loaded
#define pwmPin     5  //PWM    For led driver current control, 255 gives 2A/panel!
#define SPISPEED 25000000 //Input as Hz, 25Mhz for 128bit display, higher speeds corrupts data

const int rowAdrsPin[] = {0, 1, 2, 3}; //Row decoder pins, 0-11 dec values corresponds lines, 1-10 usable as 0 and 11 lines are missing all leds

#define ledColumns 128 //How many pixels in one row
#define firstRowAdrs 1 //first row address, 1 for 10 row display, 0 for 12 row display
#define lastRowAdrs 10 //last row address, 10 for 10 row display, 11 for 12 row display
