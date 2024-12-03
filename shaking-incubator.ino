#include <Arduino.h>

const int set1forward = 13;
const int set1back = 12;
const int set2forward = 10;
const int set2back = 11;
const int duration = 225;


void setup(){
    pinMode(set1forward, OUTPUT);
    pinMode(set1back, OUTPUT);
    pinMode(set2forward, OUTPUT);
    pinMode(set2back, OUTPUT);
    digitalWrite(set1forward, LOW);
    digitalWrite(set1back, LOW);
    digitalWrite(set2forward, LOW);
    digitalWrite(set2back, LOW);
}

void loop(){
    // Begin
    digitalWrite(set1forward, HIGH);
    delay(duration);
    // Delay
    digitalWrite(set1forward, LOW);
    digitalWrite(set2forward, HIGH);
    delay(duration);
    // Next step
    digitalWrite(set2forward, LOW);
    digitalWrite(set1back, HIGH);
    delay(duration);
    // Delay
    digitalWrite(set1back, LOW);
    digitalWrite(set2forward, HIGH);
    delay(duration);
}