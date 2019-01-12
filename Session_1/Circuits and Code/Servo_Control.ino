
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//variable used to define servos angle.
float pos = 0; 

// variable to store the servo position
float ang = 0;

// Servos sweep speed.
float vel = 0.1;

void setup() {

  //command for attatching a servo to a specific pin.
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
}

void loop() {

 //do some maths
 pos = 90 + 20*sin(ang);

 //increase angle variable.
 ang += vel;

 //command to send servo to specific angle
 myservo.write(pos);

 //wait a little bit to let the servo reach its goal position.
 delay(50);


}

