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

const int pushButton = 11;
volatile int counter;

long dutyCycleRandNumber;

// the setup() method runs once, when the sketch starts

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(pushButton, INPUT);
}

// the loop() methor runs over and over again,
// as long as the board has power

void loop() {
  // put your main code here, to run repeatedly:

counter = 0;
  while(counter < 1)
  { 
    Serial.println("in the while loop");
 
 randomSeed(analogRead(A0));
 
    dutyCycleRandNumber = random(256);
    analogWrite(greenLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(256);
    analogWrite(redLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(256);
    analogWrite(blueLED, dutyCycleRandNumber);
    delay(500);
    
    if(digitalRead(pushButton) == HIGH)//first press of pushbutton
    {
       Serial.println("First button press");
      counter++;
     
        digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
     // delay(1000);
    }
  }//end while loop

  while(counter > 0 && counter < 10)
  {
    //Serial.println("In the next while loop");
    if(digitalRead(pushButton)== HIGH)//out of the loop., now all subsequent press of pushbutton
    {
      Serial.println("another button press");
      freezeLight();
    }   
 }
  
}//end main

void freezeLight()
{
dutyCycleRandNumber = random(256);
    analogWrite(greenLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(256);
    analogWrite(redLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(256);
    analogWrite(blueLED, dutyCycleRandNumber);
    delay(500);
}
