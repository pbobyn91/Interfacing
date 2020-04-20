const int piezo = 23;
const int sensor = 0;
const int LED = 22;

int sensorMin = 1023;
int sensorValue = 0;
int sensorMax = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(piezo, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);

  while (millis() < 5000) {
    sensorValue = touchRead(sensor);
    Serial.println(sensorValue);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = touchRead(sensor);

  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  sensorValue = constrain(sensorValue, 0, 255);

  analogWrite(LED, sensorValue);
  analogWrite(piezo, sensorValue);
}
