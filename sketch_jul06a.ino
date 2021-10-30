#include <Servo.h>

#define SERVO_PIN 8

Servo hServo;

void setup ()
{ 
  hServo.attach(SERVO_PIN);
}

void loop()
{
  hServo.write(0);
  delay(1000);
  
  hServo.write(45);
  delay(1000);
  
  hServo.write(90);
  delay(1000);
}
