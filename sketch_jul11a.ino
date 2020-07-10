#include <Servo.h>
Servo motor; // servo object
int trig1 = 2; // pin of ultrasonic1
int echo1 = 3; // pin of ultrasonic1
int trig2 = 5; // pin of ultrasonic2
int echo2 = 6; // pin of ultrasonic2
int x1 = 0; // duration of pulses of ultrasonic1
int d1 = 0; // distance of ultrasonic1
int x2 = 0; // duration of pulses of ultrasonic2
int d2 = 0; // distance of ultrasonic2

void setup() {
  motor.attach(10); // servo motor pin
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  Serial.begin(9600);
}

void loop() {
digitalWrite(trig1,LOW);
delayMicroseconds(2);
digitalWrite(trig1,HIGH);
delayMicroseconds(10);
digitalWrite(trig1,LOW);

digitalWrite(trig2,LOW);
delayMicroseconds(2);
digitalWrite(trig2,HIGH);
delayMicroseconds(10);
digitalWrite(trig2,LOW);

x1 = pulseIn(echo1,HIGH);
d1 = x1 * 0.034 / 2; // distance in cm
Serial.print("Distance of ultrasonic1 is: ");
Serial.println(d1);

x2 = pulseIn(echo2,HIGH);
d2 = x2 * 0.034 / 2; // distance in cm
Serial.print("Distance of ultrasonic2 is: ");
Serial.println(d2);

while (d1>0 && d1<=100){ // Big Size
  motor.write(90); // 90 degrees
}
while (d2>0 && d2<=20 && d1>100){ // Medium Size
  motor.write(160); // 160 degrees
}
while(d1>100 && d2>20) { // Small Size
  motor.write(45); // 45 degrees
}
}
