#include <thButton.h>

#include <Servo.h> 

Servo Aservo; //Servo số 1 
Servo Bservo; //Servo số 2
Servo Cservo; //Servo số 3
Servo Dservo; //Servo số 4
Servo Eservo; //Servo số 5
Servo Fservo; //Servo số 6

thButton B0(2); //Nút nhấn B0
thButton B1(3); //Nút nhấn B1
thButton B2(4); //Nút nhấn B2
thButton B3(5); //Nút nhấn B3
thButton B4(6); //Nút nhấn B4
 
int pos = 0; //Góc xoay
 
void setup() 
{ 
  Aservo.attach(13);
  Bservo.attach(12);
  Cservo.attach(11);
  Dservo.attach(10);
  Eservo.attach(9);
  Fservo.attach(8);
  
  Aservo.write(0);
  Bservo.write(0);
  Cservo.write(0);
  Dservo.write(0);
  Eservo.write(0);
  Fservo.write(0);
}
 
void loop() 
{ 
 {if (B0.onPress())
  { pos += 45;
  if (pos > 180) {pos = 0;}   
    Serial.println();
    Serial.print();
    Serial.println();
  Aservo.write(pos);
 } 
}
 {if (B1.onPress())
  { pos += 15;
  if (pos > 180) {pos = 0;}
    Serial.println();
    Serial.print();
    Serial.println();
  Bservo.write(pos);
 }
  }
} 
