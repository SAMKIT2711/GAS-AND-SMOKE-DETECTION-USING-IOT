#include <Servo.h>
Servo myservo;
int flame = 10;
int smoke = 9;
int red = 6;
int green = 7 ;
int buzzer = 13 ;
int incoming=0;//hi

void setup ()
{
  pinMode (flame, INPUT) ;
  pinMode (smoke, INPUT) ;
  pinMode (red, OUTPUT) ;
  pinMode (green, OUTPUT) ;
  pinMode (buzzer, OUTPUT) ;
  Serial.begin(38400);//hi
  myservo.attach(8);
  myservo.write(0);
}

void loop ()
{
  int fval = digitalRead (flame) ;
  int sval = digitalRead(smoke);
  Serial.print("fval = ");
  Serial.println(fval);
  Serial.print("sval = ");
  Serial.println(sval);
  
  if ( sval == HIGH or fval == HIGH)
  {
    Serial.println(" WARNING! ");
    Serial.println(incoming);//hi
    Serial.available()>0;
    incoming = Serial.read();//hi
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(green, LOW);
    myservo.write(180);
    
  }
  else
  {
    Serial.println(" SAFE ");
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(buzzer, LOW);
    myservo.write(0);
  }
  delay(100);
}
  
