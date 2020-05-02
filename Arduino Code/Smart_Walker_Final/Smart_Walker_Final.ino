#include <NewPing.h>

#define trig0 2
#define echo0 2

#define trig1 5
#define echo1 5

#define trig2 4
#define echo2 4

#define trig3 3
#define echo3 3


#define maxD 400

  NewPing sensor0(trig0, echo0, maxD);
  NewPing sensor1(trig1, echo1, maxD);
  NewPing sensor2(trig2, echo2, maxD);
  NewPing sensor3(trig3, echo3, maxD);
  
float distance0, distance1, distance2, distance3;

void myTone(byte pin, uint16_t frequency, uint16_t duration)
{ // input parameters: Arduino pin number, frequency in Hz, duration in milliseconds
  unsigned long startTime=millis();
  unsigned long halfPeriod= 1000000L/frequency/2;
  pinMode(pin,OUTPUT);
  while (millis()-startTime< duration)
  {
    digitalWrite(pin,HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(pin,LOW);
    delayMicroseconds(halfPeriod);
  }
  pinMode(pin,INPUT);
}


void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  distance0 = sensor0.ping_cm();
  delay(20);

  distance1 = sensor1.ping_cm();
  delay(20);

  distance2 = sensor2.ping_cm();
  delay(20);

  distance3 = sensor3.ping_cm();
  delay(20);

  Serial.print("D 0: " + String(int(distance0)) + "cm  ");
  Serial.print("D 1: " + String(int(distance1)) + "cm  ");
  Serial.print("D 2: " + String(int(distance2)) + "cm  ");
  Serial.print("D 3: " + String(int(distance3)) + "cm  ");
  Serial.println();

  if(distance0 < 10){
    digitalWrite(2, HIGH);
    Serial.print("X ");
  }
  else{
    digitalWrite(2, LOW);
    Serial.print("O ");
  }
   if(distance1 < 10){
    digitalWrite(3, HIGH);
    Serial.print("X ");
  }
  else{
    digitalWrite(3, LOW);
    Serial.print("O ");
  }
   if(distance2 < 10){
    digitalWrite(4, HIGH);
    Serial.print("X ");
  }
  else{
    digitalWrite(4, LOW);
    Serial.print("O ");
  }
   if(distance3 < 10){
    digitalWrite(5, HIGH);
    Serial.print("X ");
  }
  else{
    digitalWrite(5, LOW);
    Serial.print("O ");
  }
  if((distance1<10 || distance2< 10) || (distance3<10 || distance0<10)){
    myTone(7,1070, 100);
  }
  delay(150);
}
