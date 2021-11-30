// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

const int analogInPinA1 = A1;  
const int analogOutPin3 = 3;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)

int sensorValueA2 = 0;        // value read from the pot
int outputValue3 = 0;

void setup() {
  
}

void loop() {
  p1();
  p2();
}

void p1(){
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}

void p2(){
   // read the analog in value:
  sensorValueA2 = analogRead(analogInPinA1);
  // map it to the range of the analog out:
  outputValue3 = map(sensorValueA2, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin3, outputValue3);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}