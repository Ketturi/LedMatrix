int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int multiplexPin[] = {2,3,4,5};

unsigned long displaydata=1;
int count = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  for (int i = 0; i<4; i++){
      pinMode(multiplexPin[i], OUTPUT);
    }
}

void loop() {
  for (byte counter =1; counter<=12; counter++){
    multiplexRow(counter);
   
      if (displaydata >= 0x7FFFFFFF) {displaydata = 1;}
       digitalWrite(latchPin, LOW);
       shiftOut(dataPin, clockPin, LSBFIRST, displaydata >> 0);
       shiftOut(dataPin, clockPin, LSBFIRST, displaydata >> 8);
       shiftOut(dataPin, clockPin, LSBFIRST, displaydata >> 16);
       shiftOut(dataPin, clockPin, LSBFIRST, displaydata >> 24);
       digitalWrite(latchPin, HIGH);
      if (count == 10){
        displaydata = displaydata << 1;
        count=0;
     }
  }   

count++;
}

/*void shiftOut32(uint32_t data){
  digitalWrite(latchPin, LOW);
    for (int b = 0; b<31; b++){
      if (bitRead(data, b)==1){
        digitalWrite(dataPin, HIGH);
      }
      else{
        digitalWrite(dataPin, LOW);
      }
  }
  
  __asm__("nop\n\t");
  digitalWrite(clockPin, LOW);
  __asm__("nop\n\t");
  digitalWrite(clockPin, HIGH);
  __asm__("nop\n\t");
  digitalWrite(latchPin, HIGH);
  __asm__("nop\n\t");
}
*/

void multiplexRow(byte multiRow)
{
  for (int i =0;i<4;i++)
  {
    if (bitRead(multiRow, i)==1)
    {
      digitalWrite(multiplexPin[i], HIGH);
    }
    else
    {
      digitalWrite(multiplexPin[i], LOW);
    }
  }
}