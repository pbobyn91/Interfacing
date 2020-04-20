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
  pinMode(A0, INPUT);

  attachInterrupt(pushButton, changeLights, CHANGE);
}

// the loop() methor runs over and over again,
// as long as the board has power

void loop(){
 
   while(counter < 1)
   {
    randomLights();
   }
 
}//end main

void changeLights()
{
  int onPin, offPin_1, offPin_2;

  counter++;

  int beacon = counter % 3;
     
   if(beacon == 0)
   {
    onPin = greenLED;
    offPin_1 = redLED;
    offPin_2 = blueLED;
   }
   else if(beacon == 1)
   {
    onPin = redLED;
    offPin_1 = greenLED;
    offPin_2 = blueLED;
   }
   else
   {
    onPin = blueLED;
    offPin_1 = greenLED;
    offPin_2 = redLED;
   }

  digitalWrite(onPin, HIGH);
  digitalWrite(offPin_1, LOW);
  digitalWrite(offPin_2, LOW);
  delay(200);
}

void randomLights()
{
   int onPin = random(0, 3);
   
   int offPin_1;
   int offPin_2;
   
   if(onPin == greenLED)
   {
    offPin_1 = redLED;
    offPin_2 = blueLED;
   }
   else if(onPin == redLED)
   {
    offPin_1 = greenLED;
    offPin_2 = blueLED;
   }
   else
   {
    offPin_1 = greenLED;
    offPin_2 = redLED;
   }
  
    digitalWrite(onPin, HIGH);
    digitalWrite(offPin_1, LOW);
    digitalWrite(offPin_2, LOW);
    delay(100);

}
