/* LED Blink, Teensyduino Tutorial #1
   http://www.pjrc.com/teensy/tutorial.html
 
   This example code is in the public domain.
*/

// Teensy 2.0 has the LED on pin 11
// Teensy++ 2.0 has the LED on pin 6
// Teensy 3.x / Teensy LC have the LED on pin 13
const int greenLED = 5;
const int blueLED = 9;
const int redLED = 6;

const int pushButton = 15;
volatile int counter;

long dutyCycleRandNumber;

// the setup() method runs once, when the sketch starts

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

// the loop() methor runs over and over again,
// as long as the board has power

void loop() {
  randomSeed(analogRead(A0));
  dutyCycleRandNumber = random(256);
  analogWrite(greenLED, dutyCycleRandNumber);
  dutyCycleRandNumber = random(256);
  analogWrite(blueLED, dutyCycleRandNumber);
  dutyCycleRandNumber = random(256);
  analogWrite(redLED, dutyCycleRandNumber);
  delay(500);
}
