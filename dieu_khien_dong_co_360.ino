#include <Servo.h>
#include <thButton.h>

Servo myservo;
Servo gservo;

thButton Button (2);

int pos = 0;

void setup ()
{
 Serial.begin(9600);
 Serial.println();
 
 myservo.attach(8);
 gservo.attach (9);
}

void loop ()
{
 if (Button.isPress())
  { Serial.println (pos);
   Serial.print("tang len 30 do");
    pos += 30;
  myservo.write(pos);
  gservo.write(pos);
  }
}
