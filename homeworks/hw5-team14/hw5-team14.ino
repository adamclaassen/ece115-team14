/*
 * Team 14 Homework 5
 * Adam Becker
 * Adam Claassen
 * Tianchin Fu
 * Luke Hurtig
 */

byte sensorPin = A0;
byte measureDelay = 20;
byte avgN = 10;
int avgArr[avgN] = {};


void setup(){
  Serial.begin(9600);
  for(int i = 0; i<avgN; i++){
    avgArr[i] = 0;
  }
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

int updateAvg(int value){
  int sum = 0;
  for(int i = avgN-1; i > 0; i--){
    avgArr[i] = avgArr[i-1];
  }
  avgArr[0] = value;
  for(int k = 0; k<avgN; k++){
    sum += avgArr[k];
  }
  return sum/avgN;
}

