/* LED Blink, Teensyduino Tutorial #1
   http://www.pjrc.com/teensy/tutorial.html
 
   This example code is in the public domain.
*/

int redPin =  20;
int greenPin =  23;
int bluePin =  21;
int button1 = 8;
int button2 = 10;

void setup()   {
  Serial.begin(38400);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

int redIntensity = 0;
int mode = 0;

void loop()                     
{
  // set all 3 pins to the desired intensity
  analogWrite(redPin, redIntensity);
  if (mode == 0) {
    // in mode zero, fade from red to green
    analogWrite(greenPin, 255 - redIntensity);
    analogWrite(bluePin, 0);
  } else {
    // in mode one, fade from red to blue
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255 - redIntensity);
  }
  
  if (digitalRead(button1) == LOW) {
    // use mode zero when the first button is pressed
    mode = 0;
    Serial.println("mode 0");
  }
  if (digitalRead(button2) == LOW) {
    // use mode one when the first button is pressed
    mode = 1;
    Serial.println("mode 1");
  }
  
  // remain at this color, but not for very long
  delay(10);
  
  // increase the red
  redIntensity = redIntensity + 1;
  
  // since 255 is the maximum, set it back to 0
  // when it increments beyond 255
  if (redIntensity > 255) {
    redIntensity = 0;
  }
}
