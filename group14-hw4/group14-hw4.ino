/*
 * Team 14 Homework 4
 * Adam Becker
 * Adam Claassen
 * Tianchin Fu
 * Luke Hurtig
 */

int sensorPin = A0;
int measureDelay = 20;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.print(analogRead(A0));
  delay(measureDelay);
}

