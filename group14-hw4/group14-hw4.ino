/*
 * Team 14 Homework 4
 * Adam Becker
 * Adam Claassen
 * Tianchin Fu
 * Luke Hurtig
 */

int sensorPin = A0;
int measureDelay = 20;
double distConst = (450.0/1024.0);
int distOffset = 100;

void setup(){
  Serial.begin(9600);
}

void loop(){
  sensorRead();
}

void sensorRead(){
  Serial.print((analogRead(A0)*distConst)+distOffset);
  Serial.println(" cm");
  delay(measureDelay);
}


