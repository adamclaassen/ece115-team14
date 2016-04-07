
int fwdPin = 10;
int revPin = 11;
int brkPin = 12;

const int filterSize = 10;
int filter_array_index = 0;

int mov_avg_filter[filterSize] = {};

int adc_thresh_value = 369;

bool brake_state = false;

void setup() {
  pinMode(fwdPin, OUTPUT);
  pinMode(revPin, OUTPUT);
  pinMode(brkPin, OUTPUT);
  throttle_en();

  for(int i = 0; i<filterSize; i++){
    mov_avg_filter[i] = 0;
  }
}

void loop() {
  update_dist();
  if(get_avg()>adc_thresh_value){
    if(!brake_state){
      brake_en();
    }
  }else{
    if(brake_state){
      throttle_en();
    }
  }
}

void brake_en(){
  digitalWrite(fwdPin, HIGH);
  digitalWrite(revPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(brkPin, HIGH);
  brake_state = true;
}

void throttle_en(){
  digitalWrite(brkPin, LOW);
  delayMicroseconds(10);
  digitalWrite(revPin, LOW);
  digitalWrite(fwdPin, LOW);
  brake_state = false;
}

void update_dist(){
  mov_avg_filter[filter_array_index] = analogRead(A0);
  filter_array_index++;
  if(filter_array_index>=filterSize){
    filter_array_index=0;
  }
}

int get_avg(){
  int sum = 0;
  for(int i = 0; i<filterSize; i++){
    sum += mov_avg_filter[i];
  }
  return sum/filterSize;
}

