//Code for making car scoot forward every one second

unsigned long Timer
int Interval = 1000;
int revPin = 11;
int fwdPin = 10;

void setup(){

Timer = millis();
pinMode(revPin, OUTPUT);
pinMode(fwdPin, OUTPUT);
digitalWrite(revPin, HIGH);

}
void loop(){
	if(millis() - Timer >= Interval){
		digitalWrite(fwdPin, LOW);
		Timer = millis();

	}
	else{ 
		digitalWrite(fwdPin, HIGH);
		}
}
