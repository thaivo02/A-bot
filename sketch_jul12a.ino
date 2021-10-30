#define Asensor 9
void setup()
{
  pinMode(Asensor,INPUT);
  Serial.begin(9600);
}
void loop()
{
  Serial.print("Gia tri cam bien:");
  Serial.println(digitalRead(Asensor));
  delay(1000);
} 
