/***********************
 * Practical Question: Winter 2020
 * 
 * Level Achieved: A
 * 
 * Status: Complete
 * 
 * @author: Patrick Bobyn (boby0003)
 */

#define DATA 20      // SER
#define LATCH 17     // RCLK
#define CLK 14       // SRCLK

#define TEMP 19       // Thermistor

int state = 0;
IntervalTimer timer;

const byte numbers[10] =
{
  B11000000,  // 0
  B11111001,  // 1
  B10100100,  // 2
  B10110000,  // 3
  B10011001,  // 4
  B10010010,  // 5
  B10000010,  // 6
  B11111000,  // 7
  B10000000,  // 8
  B10010000   // 9
};

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  Serial.begin(9600);
  timer.begin(stateChange, 1000000);
  delay(100);
}

float get_temp(){

  // local variables for temp and get the read from TEMP
  float celcius = 0;
  int code = analogRead(TEMP);

  // Convert code to celcius
  if (code <= 289) {
    celcius = 5 + (code - 289) / 9.82;
  }
  if (code > 289 && code <= 342) {
    celcius = 10 + (code - 342) / 10.60;
  }
  if (code > 342 && code <= 398) {
    celcius = 15 + (code - 398) / 11.12;
  }
  if (code > 398 && code <= 455) {
    celcius = 20 + (code - 455) / 11.36;
  }
  if (code > 455 && code <= 512) {
    celcius = 25 + (code - 512) / 11.32;
  }
  if (code > 512 && code <= 566) {
    celcius = 30 + (code - 566) / 11.00;
  }
  if (code > 566 && code <= 619) {
    celcius = 35 + (code - 619) / 10.44;
  }
  if (code > 619 && code <= 667) {
    celcius = 40 + (code - 667) / 9.73;
  }
  if (code > 667) {
    celcius = 45 + (code - 712) / 8.90;
  }

  // convert to fahrenheit
  float fahrenheit = celcius * 9/5 + 32;
  
  // print temperature to console
  Serial.print("Temperature: ");
  Serial.print(code);
  Serial.print(" (raw) ");
  Serial.print(celcius);
  Serial.print(" Celcius ");
  Serial.print(fahrenheit);
  Serial.println(" Fahrenheit");
  
  // return the temp based on state
  if (state == 0){
    return celcius;
  } else {
    return fahrenheit;
  }
}

// Register closest to Teensy is 1's
// Register closest to 7-segs is 10's

void loop() {

  // get temp
  int temp = (int) get_temp();

  // split temp into ones and tens
  int ones = temp % 10;
  int tens = temp / 10;

  // print out based on state
  if (state == 0){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLK, MSBFIRST, numbers[tens]);
    shiftOut(DATA, CLK, MSBFIRST, numbers[ones]);
    digitalWrite(LATCH, HIGH);
  } else {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLK, MSBFIRST, numbers[tens]);
    shiftOut(DATA, CLK, MSBFIRST, numbers[ones]&127);
    digitalWrite(LATCH, HIGH);
  }
  delay(1000);
}

void stateChange(){
  noInterrupts();
  if (state == 1){
    state = 0;
  } else {
    state = 1;
  }
  interrupts();
}
