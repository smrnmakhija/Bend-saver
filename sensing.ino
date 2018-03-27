/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

#include <LiquidCrystal.h> // includes the LiquidCrystal Library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

char ch;
int Contrast=15;
const int trigPin = 10;
const int echoPin = 8;

long duration;
long speedcm;
int distanceCm1,distanceCm2;

void setup() {
Serial.begin(9600);
  Serial.println("LCD test with PWM contrast adjustment");
  pinMode(13,OUTPUT);
  analogWrite(6,Contrast);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(10);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm1=duration*0.034/2;

lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm1);// Prints the distance value from the sensor
lcd.print(" cm  ");
if (distanceCm1<100)
 {
  lcd.setCursor(0,1);
  lcd.print("ALERT");
 }
delay(10);

duration = pulseIn(echoPin, HIGH);
distanceCm2=duration*0.034/2;

speedcm=  (distanceCm1-distanceCm2)/10;
lcd.setCursor(1,1); //ts the location at which subsequent text written to the LCD will be displayed
lcd.print("Speed: ");//ts string "Distance" on the LCD
Serial.println(speedcm);
lcd.print(speedcm);//s the distance value from the sensor
lcd.print(" cm/s  ");


}
void serialEvent()
{
     if (Serial.available())
  {
    ch= Serial.read();
    if(ch=='A' && Contrast<255)
    {
      Contrast=Contrast+1;
    }
    if(ch=='B' && Contrast>0)
    {
      Contrast=Contrast-1;
    }
        if(ch=='N')
    {
      analogWrite(9,28836);
    }
       if(ch=='F')
    {
      analogWrite(9,0);
    }
    analogWrite(6,Contrast);
    Serial.println("Current contrast");
    Serial.println(Contrast);
  }
}

