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

  byte leds = 0;
 
  for (int i = 7; i >= 0; i--){
    bitSet(leds, i);
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLOCK, LSBFIRST, leds);
    digitalWrite(LATCH, HIGH);
    delay(500);
    bitClear(leds, i);
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLOCK, LSBFIRST, leds);
    digitalWrite(LATCH, HIGH);
  }

  for (int i = 0; i < 8; i++){
    bitSet(leds, i);
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLOCK, LSBFIRST, leds);
    digitalWrite(LATCH, HIGH);
    delay(500);
    bitClear(leds, i);
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLOCK, LSBFIRST, leds);
    digitalWrite(LATCH, HIGH);
  }
}
