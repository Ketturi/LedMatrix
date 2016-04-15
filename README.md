# LedMatrix
128x10 LED matrix IoT display.

ESP8266 WiFi module controls daisychained 32x10 led display units.
![Display](https://raw.githubusercontent.com/Ketturi/LedMatrix/master/Hardware/IMG_1677.jpg)

## Hardware
![Display Backside](https://raw.githubusercontent.com/Ketturi/LedMatrix/master/Hardware/IMG_1828.jpg)
Custom build enclosure to hold four display modules, their interlinking cables, power busbars and controller board together. Acrylic parts are lasercut from dxf images designed in Autodesk Fusion360.
[3D CAD Model in A360](http://a360.co/1Sen1dj).

[Control board](https://github.com/Ketturi/LedMatrix/tree/master/Hardware/ControlPCB) for connectinc ESP8266 module to display modules is designed in eagle and is made by milling it with CNC routter. 
Display modules are connected to ESP8266 with high speed SPI for matrix column data, and 4 parallel lines for matrix row address.
![Control board](https://raw.githubusercontent.com/Ketturi/LedMatrix/master/Hardware/ControlPCB/Board.pcb.png)
![Schematics](https://raw.githubusercontent.com/Ketturi/LedMatrix/master/Hardware/ControlPCB/Schematic.png)
Display modules used in this single prototype are propriety, and do not contain make or model. There is no other available information of these, and all work here is done trough reverse engineering.
Code and control board is easily adaptable to publicly obtainable LED matrix displays.

## Software
ESP8266 module runs arduino sketch. Arduino IDE needs [Board core files](https://github.com/esp8266/Arduino) to be able to compile software for module.
Simple function converts binary bitmap data to column data corresponding selected row and column. Data is then transferred trough SPI to column led drivers (32 bit shift register in each module daisychained together)
Row is selected trough 4-bit address. 

### ESP8266 spesific features
#### OTA Update
Software incorporates [OTA updates](http://esp8266.github.io/Arduino/versions/2.1.0/doc/ota_updates/ota_updates.html) through Arduino IDE. When ESP8266 is connected to same network as computer containing IDE, board shows in port menu.
#### WiFi Manager
ESP8266 uses [WiFi Manager](https://github.com/tzapu/WiFiManager) library that allows modifying wlan credentials and other settings without recompiling and uploading the software.
When control board is powered, it tries to connect previously saved WiFi access point. If that however fails, ESP8266 creates access point itself. By connecting this access point user can go to http://192.168.4.1 address and input their own WiFi credentials.
Credentials are saved to flash, and ESP8266 tries to connect that access point. After successful connection display is initialized and starts to show data.
### Arduino IDE board settings

| Setting | Option | Explanaition |
| --- | --- |  --- | 
| Board | Generic ESP8266 Module |Install board from http://github.com/esp8266/Arduino
| Flash Mode | QIO |Selects how flash is controlled, QIO = 4 data lines
| Flash Size | 4M (1M SPIFFS) |4MB flash IC, 1M file system (3MB for scetch&OTA)
| Debug port | Disabled |Disables serial debug, serial lines used for data lines
| Debug level | None |No debuging
| Reset Method | ck |Does not matter, no serial programming reset ability
| Flash Frequency | 40Mhz |Probably 40Mhz, 80Mhz should be carefully tested
| Upload Using | OTA |Updated over network
| CPU Frequency | 160Mhz |Speed boost for faster display
| Upload SPEED | 115200| Does not matter when using OTA
| Port | FoxMatrix at <ip> (Generic ESP8266 Module) |Select device from network, shows only when properly connected and discovered

###Kukkaconvert
Kukkaconvert.exe is small windows command line utility for converting PNG images to bitmap binary data for display.
"kukkaconvert.exe image.png" accepts 12 pixel high png black and white images and outputs binary data to output.txt file.
