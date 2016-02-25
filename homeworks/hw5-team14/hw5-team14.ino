/*
 * Team 14 Homework 5
 * Adam Becker
 * Adam Claassen
 * Tianchin Fu
 * Luke Hurtig
 */

byte sensorPin = A0;
byte measureDelay = 20;
const byte avgN = 10;
int avgArr[avgN] = {};


void setup(){
  Serial.begin(9600);
  for(int i = 0; i<avgN; i++){ //initialize array as 0's
    avgArr[i] = 0;
  }
}

void loop(){
  Serial.print(sensorTransferFunc(updateAvg(sensorRead())));
  Serial.println(" cm");
  delay(measureDelay);
}

int sensorRead(){
  return analogRead(sensorPin);
}

double sensorTransferFunc(int adcValue){ //ADC -> voltage -> distance conversion
  //ADC -> voltage conversion
  double adcConst = 0.00459; //4.7v/1024 divisions
  double voltage = adcConst*adcValue;
  if(voltage<1.4){voltage=-1;}//out of range under
  if(voltage>2.5){voltage=-2;}// out of range over
  
  //transfer function
  if(!input<0){
  double slope = 0.0072727272; //calculated from sensor datasheet V vs. 1/L graph
  double offset = -0.00818181; //calculated from sensor datasheet V vs. 1/L graph
  double invDist = (voltage*slope)+offset;
  return 1/invDist;
  }
  return voltage;
}

int updateAvg(int value){ //update the values in the moving avg function and return the new avg.
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

