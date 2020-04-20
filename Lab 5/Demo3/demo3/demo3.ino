byte SER = 14; //data
byte LATCH = 15; //RCLK
byte CLOCK = 16; //SRCLK

void setup(){
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  digitalWrite(SER, 0);
  digitalWrite(CLOCK, 0);
  digitalWrite(LATCH, 0);
  delay(1000);
}

void loop(){
  
  // loop 0 to 9 for the "tens"
  for (byte i = 0; i < 10; i++){

    int display1 = numToBits(i);
    
    // loop 0 to 9 for the "ones"
    for (byte j = 0; j <= 9; j++){

      byte num = numToBits(j);
      digitalWrite(LATCH, HIGH);
      int display2 = numToBits(j);
      shiftOut(CLOCK, SER, LSBFIRST, display2);
      shiftOut(CLOCK, SER, LSBFIRST, display1);
      digitalWrite(LATCH, LOW);
      delay(100);
    }
  }
}

byte numToBits(int someNumber) {
  switch (someNumber) {
    case 0:
      return B00000011;
      break;
    case 1:
      return B10011111;
      break;
    case 2:
      return B00100101;
      break;
    case 3:
      return B00001101;
      break;
    case 4:
      return B10011001;
      break;
    case 5:
      return B01001001;
      break;
    case 6:
      return B01000001;
      break;
    case 7:
      return B00011111;
      break;
    case 8:
      return B00000001;
      break;
    case 9:
      return B00001001;
      break;  
    default:
      return B01101101; // Error condition, displays three vertical bars
      break;   
  }
}
