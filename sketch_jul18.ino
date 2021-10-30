
#include <thButton.h>

#include <Servo.h> 

Servo Aservo; //Servo số 1 
Servo Bservo; //Servo số 2
Servo Cservo; //Servo số 3
Servo Dservo; //Servo số 4
Servo Eservo; //Servo số 5
Servo Fservo; //Servo số 6

thButton Button0(2); //Nút nhấn B0
thButton Button1(3); //Nút nhấn B1
thButton Button3(4); //Nút nhấn B3
 
int pos = 0; //Góc xoay
int temp = 0; //Gọi tên servo 
 
void setup() 
{ 
  Serial.begin(9600);
  Aservo.attach(13);
  Bservo.attach(12);
  Cservo.attach(11);
  Dservo.attach(10);
  Eservo.attach(9);
  Fservo.attach(8);
  
  Aservo.write(0);
  Bservo.write(0);
  Cservo.write(0);
  Dservo.write(30);
  Eservo.write(0);
  Fservo.write(0);
}
 
void loop() 
{ 
  if (Button0.isPress()) {temp ++;
  Serial.print("chuyen servo");
  Serial.println(temp);
  delay(200);}
  if (Button0.isRelease()) {temp = temp;
  Serial.println("temp + 0");
  delay(200);}
   if (temp > 6) {temp = 0;}
  switch (temp){
case 1:{
     Aservo.write(0);
   if (Button3.isPress())
  { pos += 15;
    Aservo.write(pos);
  }  
   if (Button1.isPress())
  { pos -= 15; 
   Aservo.write(pos);
  } 
     if (pos >180) {pos = 0;} 
   delay(130);  
    break;
  }
case 2:{
     Bservo.write(0);
   if (Button3.isPress())
  { pos += 20;
    Bservo.write(pos);
  }  
   if (Button1.isPress())
  { pos -= 20; 
   Bservo.write(pos);
  } 
     if (pos >180) {pos = 0;} 
   delay(130);  
    break;
  }
  case 3:{
     Cservo.write(0);
   if (Button3.isPress())
  { pos += 30;
    Cservo.write(pos);
  }  
   if (Button1.isPress())
  { pos -= 30; 
   Cservo.write(pos);
  }    if (pos >180) {pos = 20;} 
   delay(130);  
    break;
  }
  case 4:{
     Dservo.write(30);
   if (Button3.isPress())
  { pos += 20;
    Dservo.write(pos);
  }  
   if (Button1.isPress())
  { pos -= 20; 
   Dservo.write(pos);  
  }    if (pos >155) {pos = 25;} 
   delay(130);
    break;
  }
  case 5:{
     Eservo.write(0);
   if (Button3.isPress())
  { pos += 30;
    Aservo.write(pos);
  }  
   if (Button1.isPress())
  { pos -= 30; 
   Eservo.write(pos);  
  }    if (pos >180) {pos = 0;} 
   delay(130);
    break;
  }
  case 6:{
     Fservo.write(0);
   if (Button3.isPress())
  { pos += 35;
    Fservo.write(pos);
  }  
   if (Button1.isPress())
  { pos -= 35; 
   Fservo.write(pos); 
  }    if (pos >175) {pos = 0;} 
   delay(130); 
    break;
  default:
  //don't do anything
  Serial.println("Robot ngung su dung");
  }
  }
}
