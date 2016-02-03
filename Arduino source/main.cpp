int latchPin = 8; //Shift register pins
int clockPin = 12;
int dataPin = 11;
int enablePin = 9;

int multiplexPin[] = {2,3,4,5}; //Row decoder pin
int pwmPin = 6;

const unsigned long DisplayMatrixHello[12] = { //hello!
0x00000000,
0x00000000,  
0x00024000, 
0x44024020, 
0x44024020,
0x44624620, 
0x7C924920, 
0x44F24920, 
0x44824900,
0x44724620, 
0x00000000, 
0x00000000
};

const unsigned long DisplayMatrix[12] = { //ketturi
0x00000000,
0x00000000,
0x88000002,
0x90088000,
0xA19FE93A,
0xC2488922,
0xA3C88922,
0x92088922,
0x89CEEF22,
0x00000000,
0xFFFFFFFF,
0x00000000
};

const unsigned long DisplayMatrixLedTest[12] = { //screen test
0xFFFFFFFF,
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF, 
0xFFFFFFFF
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
  analogWrite(pwmPin, 20);
 
}

void loop() {

 /* while (Serial.available() > 0) { //Reads serial port and sets pwm value
    pwm = Serial.parseInt();
    if (Serial.read() == '\n') {
      Serial.print("PWM is set at "); Serial.println(pwm);
      analogWrite(pwmPin, pwm);
    }
  }*/

  for (byte row =0; row<=11; row++){ //Displaythingy happens here, select row, put column data in, change row, start again...
    digitalWrite(latchPin, LOW);
    digitalWrite(enablePin, LOW); 
    shiftOut(dataPin, clockPin, LSBFIRST, DisplayMatrix[row] >> 0);
    shiftOut(dataPin, clockPin, LSBFIRST, DisplayMatrix[row] >> 8);
    shiftOut(dataPin, clockPin, LSBFIRST, DisplayMatrix[row] >> 16);
    shiftOut(dataPin, clockPin, LSBFIRST, DisplayMatrix[row] >> 24);
    digitalWrite(enablePin, HIGH); 
    digitalWrite(latchPin, HIGH); 
    multiplexRow(row);      
  } 
 
}

void multiplexRow(byte multiRow){  //selects which row is illuminated, 0-11 in four bits
  for (int i =0;i<4;i++)  {
    if (bitRead(multiRow, i)==1){
      digitalWrite(multiplexPin[i], HIGH);
    }
    else{
      digitalWrite(multiplexPin[i], LOW);
    }
  }
}