
//setting output pin for LED, ensuring PWM pin.
const int ledPin =  9;

// the setup routine runs once when you press reset:
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  // print out the value you read:
  Serial.println(sensorValue);

  //map sensor value to a value between 0 and 255.
  int brightness = map(sensorValue, 0,1023,0,255);

  //outputing brightness with PWM, must be a value between 0 and 255.
  analogWrite(ledPin,brightness);
  delay(10);        // delay in between reads for stability
  
}
