// Team 14: Adam Becker, Tianchen Fu, Lukas Hurtig, Adam Claassen

const int interval = 50;
//blink LED every 1/20th of a second
const int ledPin = 13;
unsigned long ledTimer;

void setup() {
  ledTimer = millis();
  pinMode(ledPin, OUTPUT);
  //set LED to OUTPUT

}

void loop() {
 if(millis()-ledTimer >= interval){
 //save most recent blink
  if (digitalRead(ledPin) == HIGH){
    digitalWrite(ledPin, LOW);
    //if LED is on, turn it off
  }
  else{
    digitalWrite(ledPin, HIGH);
    //turn on LED
  }(ledTimer += interval); // add requested time interval
  }
  }
