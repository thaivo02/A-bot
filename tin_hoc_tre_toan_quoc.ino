#include <thButton.h>
#include <Servo.h>
#define IN1	7
#define IN2	6
#define IN3	5
#define IN4	4
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0

thButton Button0(2); //Nút nhấn B0
thButton Button1(3); //Nút nhấn B1
thButton Button3(4); //Nút nhấn B3

char junk;
String inputString="";
int pos = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;
int pos6 = 0;
int pos7 = 0;
int temp = 0;

Servo Aservo;
Servo Bservo;
Servo Cservo;
Servo Dservo;
Servo Eservo;
Servo Fservo;
Servo myservo;
Servo urservo;

void setup()                    
{
 Serial.begin(9600);  
 
 Aservo.attach(13);
 Bservo.attach(12);
 Cservo.attach(11);
 Dservo.attach(10);
 Eservo.attach(9);
 Fservo.attach(8);
 
 myservo.attach(2);
 urservo.attach(3);
 
  Aservo.write(0);
  Bservo.write(80);
  Cservo.write(0);
  Dservo.write(30);
  Eservo.write(0);
  Fservo.write(0);
 
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);

}

void motor_1_Dung() {
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
}
 
void motor_2_Dung() {
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}
 
void motor_1_Tien(int speed) { 
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);
	digitalWrite(IN1, HIGH);
	analogWrite(IN2, 255 - speed);
}
 
void motor_1_Lui(int speed) {
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);
	digitalWrite(IN1, LOW);
	analogWrite(IN2, speed);
}
 
void motor_2_Tien(int speed) {
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);
	analogWrite(IN3, speed);
	digitalWrite(IN4, LOW);
}
 
void motor_2_Lui(int speed) {
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);
	analogWrite(IN3, 255 - speed);
	digitalWrite(IN4, HIGH);
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); 
      inputString += inChar;      
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }     
    if(inputString == "a")
    {  pos1 += 30;
     Aservo.write(pos);
  if( pos1 > 180) {pos1 = 180;}
    }
    else if(inputString == "b")
    { pos1 -= 30;  
     Aservo.write(pos1);
  if( pos1 < 0) {pos1 = pos1;}
    }
        if(inputString == "c")
    {  pos2 += 30;
     Bservo.write(pos2);
  if( pos2 > 180) {pos2 = 180;}
    }
    else if(inputString == "d'")
    { pos2 -= 30;  
     Bservo.write(pos2);
  if( pos2 < 0) {pos2= pos2;}
    }
        if(inputString == "e")
    {  pos3 += 30;
     Cservo.write(pos3);
  if( pos3 > 180) {pos3 = 180;}
    }
    else if(inputString == "f")
    { pos3 -= 30;  
     Cservo.write(pos3);
  if( pos3 < 0) {pos3 = pos3;}
    }
        if(inputString == "g")
    {  pos4 += 30;
     Dservo.write(pos4);
  if( pos4 > 180) {pos4 = 180;}
    }
    else if(inputString == "h")
    { pos4 -= 30;  
     Dservo.write(pos4);
  if( pos4 < 0) {pos4 = pos4;}
    }
        if(inputString == "i")
    {  pos5 += 30;
     Eservo.write(pos5);
  if( pos5 > 180) {pos5 = 180;}
    }
    else if(inputString == "j")
    { pos5 -= 30;  
     Eservo.write(pos5);
  if( pos5 < 0) {pos5 = pos5;}
    }
        if(inputString == "k")
    { pos6 += 15;
     Fservo.write(pos6);
  if( pos6 > 180) {pos6 = 180;}
    }
    else if(inputString == "l")
    { pos6 -= 15;
     Fservo.write(pos6);
  if( pos6 < 0) {pos6 = pos6;}
    }
   for(pos7 = 0; pos7 <= 180; pos7 += 1)
   if(inputString == "m")
   {
 myservo.write(-pos7);
  urservo.write(pos7);
   }
    if(inputString == "n")
   {
 myservo.write(pos7);
  urservo.write(-pos7);
   }
   if(inputString == "o") 
   {
   motor_1_Lui(MAX_SPEED); // motor 1 lùi
   motor_2_Tien(MAX_SPEED); // motor 2 tiến
   
   }
   if(inputString == "v")
   {
   motor_1_Tien(MAX_SPEED); // motor 1 tiến
   motor_2_Lui(MAX_SPEED); // motor 2 lùi
   }
   if(inputString == "u")
   {
   	motor_1_Dung();
	motor_2_Dung();
   
   }
    inputString = "";
  }
  if (Button0.isPress()) {temp ++;
            Serial.print("chuyen servo");
            Serial.println(temp);
            }
            delay(200);
           
              if (Button0.isRelease()) {temp = temp;
              Serial.println("temp + 0");
              }delay(200);
                         if (temp > 5) {temp = 0;}
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
  Bservo.write(pos2);
if (pos2 > 175) {pos2 -= 30;}

    }
     if (Button1.isPress())
  {
    pos2 -= 30;
  Bservo.write(pos2);  
if (pos2 < 0) {pos2 = pos2;}

    } 
  }
  break;
          case 3: {
 if (Button3.isPress())
 {
  pos3 += 20;
 Cservo.write(pos3);
  if (pos3 > 90) {pos3 = pos3;}
  
  }
  if (Button1.isPress())
  {
   pos3 -= 20; 
  Cservo.write(pos3);
   if (pos3 < 0) {pos3 = pos3;}
    
   }
   
    }
      break; 
                case 4: {
 if (Button3.isPress())
 {
  pos4 += 30;
 Dservo.write(pos4);
  if (pos4 > 180) {pos4 = pos4;}
  
  }
  if (Button1.isPress())
  {
   pos4 -= 30; 
  Dservo.write(pos4);
   if (pos4 < 0) {pos4  = pos4;}
    
   }
                   case 5: {
 if (Button3.isPress())
 {
  pos5 += 30;
 Eservo.write(pos5);
  if (pos5 > 180) {pos5 = pos5;}
  
  }
  if (Button1.isPress())
  {
   pos5 -= 30; 
  Eservo.write(pos5);
   if (pos5 < 0) {pos5  = pos5;}
    
   }
                   case 6: {
 if (Button3.isPress())
 {
  pos6 += 30;
 Fservo.write(pos6);
 if (pos6 > 180) {pos6 = pos6;}
  
  }
  if (Button1.isPress())
  {
   pos6 -= 30; 
  Eservo.write(pos6);
   if (pos6 < 0) {pos6  = pos6;}
    
   }
   
    }
      break;
  default:
Serial.println("mac dinh");
                }
}
                }
}
