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

  int bitArray[]={1,3,7,15,31,63,127,255}; 
  byte bit_min = 0x00;
  byte bit_max = 0xFF;

  for(int i = 0 ; i < 8; i++){
    shiftOut(SER,CLOCK,MSBFIRST,bit_min);
    shiftOut(SER,CLOCK,MSBFIRST,bitArray[i]);
    digitalWrite(LATCH,HIGH);
    digitalWrite(LATCH,LOW);
    delay(100);
  }
  
  for(int j = 0; j < 8 ; j ++){
    shiftOut(SER,CLOCK,MSBFIRST,bitArray[j]);
    shiftOut(SER,CLOCK,MSBFIRST,bit_max);
    digitalWrite(LATCH,HIGH);
    digitalWrite(LATCH,LOW);
    delay(100);   
  }

  for(int n = 7; n > 0 ; n--){
     shiftOut(SER,CLOCK,MSBFIRST,bitArray[n]);
     shiftOut(SER,CLOCK,MSBFIRST,bit_max);  
     digitalWrite(LATCH,HIGH);
     digitalWrite(LATCH,LOW);
     delay(100);
  }
      
  for(int n = 7; n > 0 ; n--){
     shiftOut(SER,CLOCK,MSBFIRST,bit_min);
     shiftOut(SER,CLOCK,MSBFIRST,bitArray[n]);  
     digitalWrite(LATCH,HIGH);
     digitalWrite(LATCH,LOW);
     delay(100);
  }
}
