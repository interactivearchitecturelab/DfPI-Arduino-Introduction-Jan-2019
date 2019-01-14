// Servo Control without library

int servo = 9;// set servo pin
int pos = 500;

void setup() {
  pinMode(servo, OUTPUT); // set pin as output
}

void loop() {
  for (pos = 500; pos <= 2500; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoPulse(servo, pos);             // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 2500; pos >= 500; pos -= 1) { // goes from 180 degrees to 0 degrees - using pulse vals
   servoPulse(servo, pos);            // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void servoPulse(int servoPin, int pulse) {
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite(servoPin, LOW);
}
