/*
 * File: hw4-team14.ino
 * 
 * Team 14 Homework 4
 * Adam Becker
 * Adam Claassen
 * Tianchin Fu
 * Luke Hurtig
 * 
 * Program revision 1
 * Due 2016-2-23
 * 
 * This program aquires a distance measurement from the IR sensor and prints it over serial every 20ms (blocking). 
 */

int sensorPin = A0;
int measureDelay = 20;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int analogValue = sensorRead();
  Serial.println(analogValue);
  delay(measureDelay);
}

int sensorRead(){
  analogRead(sensorPin);
}

