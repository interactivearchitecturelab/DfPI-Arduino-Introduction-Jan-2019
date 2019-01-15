int servoPin = 9;
int ledPin = 13;
unsigned long previousMillis = 0; // used for timer
int pVal = 500; // starting pulse value
boolean increasePulse = true; // control state of sweep left and right
int interval = 20; // fixed value of pulsing servos DONT TOUCH
int spd = 25;// speed of increment or decrement on swee
int minPulse = 500;
int maxPulse = 2500;

int behaviourState = 0;

void setup() {
  pinMode(servoPin, OUTPUT); // set servoPin to output
  pinMode(ledPin, OUTPUT); // set ledPin to output
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis(); // get time in milliseconds
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (Serial.available() > 0) {
      byte incomingByte = Serial.read();
      if (incomingByte == '1') {
        // set state of behaviour 1
        behaviourState = 1;
      }
      if (incomingByte == '0') {
        // set state of behaviour 2
        behaviourState = 0;
      }
    }

    switch (behaviourState) {
      case 0:
        sweep(2);
        break;
      case 1:
        sweep(10);
        break;
    }

    pulse(pVal);
  }
}

void sweep(int s) {
  if (increasePulse) {
    pVal += s;
    if (pVal >= maxPulse) {
      increasePulse = false;
    }
  } else {
    pVal -= s;
    if (pVal <= minPulse) {
      increasePulse = true;
    }
  }
}

void pulse(int p) { // function for controlling servo with pulse val
  // constrain to minimum and maximum pulse
  p = constrain(p, minPulse, maxPulse);

  // pulse servo
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(p);
  digitalWrite(servoPin, LOW);
}

void pulseAngle(int angle) { //function for control servo with angle val
  int tempVal = map(angle, 0, 180, minPulse, maxPulse);
  pulse(tempVal);
}
