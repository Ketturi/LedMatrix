/*Led matrix controller
 * 
 */
#include <avr/pgmspace.h>
const int latchPin = 8; //Shift register pins
const int clockPin = 12;
const int dataPin = 11;
const int enablePin = 9;

const int multiplexPin[] = {2,3,4,5}; //Row decoder pin
const int pwmPin = 6;
int pwm = 100;
const int framerate = 8; //exponent of 2
const unsigned int imageWidth = 160;
const unsigned long imageData[60] PROGMEM= {
    0x3e3fc7e3, 0x223fcff3, 0x22060c33, 0xfa060c33, 0x02060c33, 0x72060c33, 0x22060ff3, 0x22060ff3, 0x22060c33, 0x22060c33, 0x22060c33, 0x3e060c33, 
    0x0cfe3fcf, 0x0cff3fcf, 0x0cc3300c, 0x9cc3300c, 0x9cc3300c, 0xfcc33f0c, 0x6cff3f0f, 0x6cfe300f, 0x0cc0300d, 0x0cc0300c, 0x0cc03fcc, 0x0cc03fcc, 
    0xe3fc030c, 0xf3fc030c, 0x3300030c, 0x3300030c, 0x3300030c, 0x33f003fc, 0xf3f003fc, 0xe300030c, 0x8300030c, 0xc300030c, 0x63fc030c, 0x33fc030c, 
    0x7e1f8c33, 0xff3fcc33, 0xc330cc33, 0xc3300c63, 0xc3300cc3, 0xc3300f83, 0xff300f83, 0xff300cc3, 0xc3300c63, 0xc330cc33, 0xc33fcc33, 0xc31f8c33, 
    0x007e3f80, 0x00ff3fc0, 0x00c330c0, 0x00c330c0, 0x00c330c0, 0x00c33f80, 0x00ff3f80, 0x00ff30c0, 0x00c330c0, 0x00c330c0, 0xfcc33fc0, 0xfcc33f80, 
};

void setup() { //Set pins to outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  for (int i = 0; i<4; i++){
    pinMode(multiplexPin[i], OUTPUT);
  }
  Serial.begin(9600);
  analogWrite(pwmPin, pwm); 
}

void loop() {
  setBrightness();
  for (int frame = 0; frame < imageWidth*framerate; frame++){
    for (byte row =0; row<=12; row++){ //Displaythingy happens here, select row, put column data in, change row, start again...
      shiftOut32(getRowWord((frame/framerate), row, imageWidth, imageData));
      multiplexRow(row);
     }      
  } 
}

void multiplexRow(byte multiRow){  //selects which row is illuminated, 0-11 in four bits
  for (int i =0;i<4;i++){
    if (bitRead(multiRow, i)==1){
      digitalWrite(multiplexPin[i], HIGH);
    }
    else{
      digitalWrite(multiplexPin[i], LOW);
    }
  }
}

void setBrightness(){
  while (Serial.available() > 0) { //Reads serial port and sets pwm value
    int pwm = Serial.parseInt();
    if (Serial.read() == '\n') {
      Serial.print("PWM is set at "); Serial.println(pwm);
      analogWrite(pwmPin, pwm);
    }
  }
}

void shiftOut32(unsigned long input){
digitalWrite(latchPin, LOW);
digitalWrite(enablePin, LOW); 
shiftOut(dataPin, clockPin, LSBFIRST, input >> 0);
shiftOut(dataPin, clockPin, LSBFIRST, input >> 8);
shiftOut(dataPin, clockPin, LSBFIRST, input >> 16);
shiftOut(dataPin, clockPin, LSBFIRST, input >> 24);
digitalWrite(enablePin, HIGH); 
digitalWrite(latchPin, HIGH); 
}

const unsigned long getRowWord(const unsigned int x, unsigned const int y, const unsigned int width, const unsigned long* data) {
    // Huomaa että x:n jakojäännökset saattavat olla hitaita, jos kääntäjä ei pysty mitenkään 
    // kääntäessä ennalta päättelemään, minkä arvon width saa funktiota kutsuttaessa.
    const unsigned int xa = x % width;
    const unsigned int xb = (x + 32) % width;
    const unsigned int ya = y % 12;
    const unsigned int shift = xa % 32;
    
    const unsigned int aPtr = ya + (xa / 32) * 12;
    const unsigned int bPtr = ya + (xb / 32) * 12;
    
    // Konditionaali, ettei tulisi shiftattua 32:lla 32-bittistä muuttujaa (ei määritelty, ainakaan C:ssä).
    //return shift == 0 ? data[aPtr] : ((data[aPtr] << shift) | (data[bPtr] >> (32 - shift)));
    return shift == 0 ? pgm_read_dword(data + aPtr) : ((pgm_read_dword(data + aPtr) << shift) | (pgm_read_dword(data + bPtr) >> (32 - shift)));
}
