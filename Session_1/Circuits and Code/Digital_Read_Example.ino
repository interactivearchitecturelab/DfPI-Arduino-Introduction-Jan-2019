
//DfPI Tutorial Code
//Sean Malikides
//Oct 2017

/*
Code Function Description

  - Reads a digital input on pin 2, prints the result to the serial monitor.
  - Uses push button to turn a light on and off.
  
*/

// declare variable "pushButton" as an integer, and assign it the value 2, for later pin assignment. 
int pushButton = 4;

// constants won't change. Used here to set a pin number.
const int ledPin =  13;      // the number of the LED pin

// the setup routine runs once when you press reset.
void setup() {
  
  // initialize serial communication at 9600 bits per second.
  Serial.begin(9600);

  // make the pushbutton's pin an input.
  pinMode(pushButton, INPUT);

  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  
}

// the loop routine runs over and over again forever.
void loop() {
  
  // read the input pin.
  int buttonState = digitalRead(pushButton);
  
  // print out the state of the button, So you can see what the state of the pushbutton is.
  Serial.println(buttonState);

  if (buttonState == HIGH) {
    
    //Turn the LED on.
    digitalWrite(ledPin, HIGH);
    
  } else {

    //Turn the LED off.
    digitalWrite(ledPin, LOW);
    
  }

  //just a little delay for stability.
  delay(10);
  
}



