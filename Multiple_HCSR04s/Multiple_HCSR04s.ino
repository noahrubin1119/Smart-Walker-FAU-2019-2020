#include <NewPing.h>

#define trig0 8
#define echo0 8

#define trig1 9
#define echo1 9

#define trig2 10
#define echo2 10

#define trig3 11
#define echo3 11

#define maxD 400

  NewPing sensor0(trig0, echo0, maxD);
  NewPing sensor1(trig1, echo1, maxD);
  NewPing sensor2(trig2, echo2, maxD);
  NewPing sensor3(trig3, echo3, maxD);
  
float distance0, distance1, distance2, distance3;

void setup() {
  
  Serial.begin(9600);
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

  delay(500);
}
