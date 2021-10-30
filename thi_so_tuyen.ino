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

int pos1 = 0; //Bien xoay thu nhat
int pos2 = 0; //Bien xoay thu hai
int pos3 = 80; //Bien xoay thu ba
int pos4 = 0; //Bien xoay thu tu  
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
  Bservo.write(80);
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
            }
            delay(200);
           
              if (Button0.isRelease()) {temp = temp;
              Serial.println("temp + 0");
              }delay(200);
                         if (temp > 5) {temp = 0;}
                   
                switch (temp) {
     case 1:{
 if (Button3.isPress())
 {
  pos1 += 15;
  Aservo.write(pos1);
if (pos1 > 180) {pos1 -= 30;}
  }
  if (Button1.isPress())
 {
  pos1 -= 15;
  Aservo.write(pos1);
if (pos1 < 0) {pos1 = pos1;}
  }
  }
   
  break;
        case 2: {     
  if (Button3.isPress())
  {
    pos2 += 30;
  Cservo.write(pos2);
if (pos2 > 175) {pos2 -= 30;}

    }
     if (Button1.isPress())
  {
    pos2 -= 30;
  Cservo.write(pos2);  
if (pos2 < 0) {pos2 = pos2;}

    } 
  }
  break;
          case 3: {
 if (Button3.isPress())
 {
  pos3 += 20;
 Dservo.write(pos3);
  if (pos3 > 90) {pos3 = pos3;}
  
  }
  if (Button1.isPress())
  {
   pos3 -= 20; 
  Dservo.write(pos3);
   if (pos3 < 0) {pos3 = pos3;}
    
   }
   
    }
      break; 
                case 4: {
 if (Button3.isPress())
 {
  pos4 += 30;
 Eservo.write(pos4);
  if (pos4 > 180) {pos4 = pos4;}
  
  }
  if (Button1.isPress())
  {
   pos4 -= 30; 
  Dservo.write(pos4);
   if (pos4 < 0) {pos4  = pos4;}
    
   }
   
    }
      break;
  default:
  Bservo.write(80);
Serial.println("mac dinh");
                }
                
                }          

