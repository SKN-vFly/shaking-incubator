#include<Arduino.h>

const int set1forward = 12;
const int set1back = 13;
const int set2forward = 10;
const int set2back = 11;
bool play = true;
const int DELAY = 1;
unsigned long previousMillis = 0;
unsigned long period = 1100;
unsigned long pulse_len = 100;
unsigned long pulse_delay = 500;




void pulse_full(int len);

void pulse(int len, int delay, int pin);

void setup() {
  pinMode(set1forward, OUTPUT);
  pinMode(set1back, OUTPUT);
  pinMode(set2forward, OUTPUT);
  pinMode(set2back, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  unsigned long currentMillis = millis();
  if(Serial.available()>0){
    String inp = Serial.readStringUntil('\n');
    period = inp.toInt();
  }
  Serial.println(period);
      pulse(pulse_len, pulse_delay, set1forward);
      
      pulse(pulse_len, pulse_delay, set2forward);
      
      pulse(pulse_len,pulse_delay, set1back);
      
      pulse(pulse_len, pulse_delay, set2back);
      
  if (currentMillis - previousMillis >= period) {
     //pulse_full(period/2);
     
     previousMillis = currentMillis;
  }
}
/*
void pulse_full(int len){
    digitalWrite(out1pin, LOW);
    digitalWrite(out2pin, HIGH);
    digitalWrite(out3pin, LOW);
    digitalWrite(out4pin, HIGH); 
    delay(len - DELAY);
    digitalWrite(out2pin, LOW);
    digitalWrite(out4pin, LOW);
    delay(DELAY);
    
    digitalWrite(out1pin, HIGH);
    digitalWrite(out2pin, LOW);
    digitalWrite(out3pin, HIGH);
    digitalWrite(out4pin, LOW); 
    delay(len - DELAY);
    digitalWrite(out1pin, LOW);
    digitalWrite(out3pin, LOW);
    
    delay(DELAY);    
}
*/
void pulse(int len, int delay int pin){
  digitalWrite(pin, HIGH);
  delay(len);
  digitalWrite(pin, LOW);
  delay(delay)
}