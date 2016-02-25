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
  Serial.print(sensorTransferFunc(sensorRead()));
  Serial.println(" cm");
  delay(measureDelay);
}

int sensorRead(){
  double adcConst = 0.00459; //4.7v/1024 divisions
  double voltage = adcConst*analogRead(A0);
  if(voltage<1.4){voltage=-1;}//out of range under
  if(voltage>2.5){voltage=-2;}// out of range over
}

double sensorTransferFunc(double input){ //voltage -> distance conversion
  if(!input<0){
  double slope = 0.0072727272; //calculated from sensor datasheet V vs. 1/L graph
  double offset = -0.00818181; //calculated from sensor datasheet V vs. 1/L graph
  double invDist = (input*slope)+offset;
  return 1/invDist;
  }
  return input;
}
