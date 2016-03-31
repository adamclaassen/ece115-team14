//Code for making car scoot backwards every one second

unsigned long Timer;
int Interval = 1000;
int revPin = 11;
int fwdPin = 10;

void setup(){

Timer = millis();
pinMode(revPin, OUTPUT);
pinMode(fwdPin, OUTPUT);
digitalWrite(fwdPin, HIGH);

}
void loop(){
	if(millis() - Timer >= Interval){
		digitalWrite(revPin, LOW);
		TImer = millis();

	}
	else{ 
		digitalWrite(revPin, HIGH);
		}
}
