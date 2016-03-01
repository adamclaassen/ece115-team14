/*
 * File: hw5-team14.ino
 *
 * Team 14 Homework 5
 * Adam Becker
 * Adam Claassen
 * Tianchin Fu
 * Luke Hurtig
 *
 * Program version 0.9
 * Due 2016-03-01
 *
 * This program uses a moving average to smooth the input from the infrared ranging sensor, hopefully removing most glitches and insignificant data.
 * It also converts the averaged value to a distance before printing it over the serial port (untested/alpha feature).
 */

 #include <math.h>
 int sensorPin = A0;
 int measureDelay = 20;
 const int avgN = 10;
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
   if(voltage>2.5){voltage=-1;}//out of range under
   //if(voltage<1.4){voltage=-2;}// out of range over

   //transfer function
   if(voltage>0){
    double dist = 5.47824 + -0.66468*log(voltage);
    return dist;
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
