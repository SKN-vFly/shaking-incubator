#include <Arduino.h>

const int set1forward = 12;
const int set1back = 13;
const int set2forward = 11;
const int set2back = 10;
const int duration = 1000;


void setup(){
    pinMode(set1forward, OUTPUT);
    pinMode(set1back, OUTPUT);
    pinMode(set2forward, OUTPUT);
    pinMode(set2back, OUTPUT);
    digitalwrite(set1forward, LOW);
    digitalwrite(set1back, LOW);
    digitalwrite(set2forward, LOW);
    digitalwrite(set2back, LOW);
}

void loop(){
    // Begin
    digitalwrite(set1forward, HIGH);
    digitalwrite(set2back, HIGH);
    delay(duration);
    // Delay
    digitalwrite(set1forward, LOW);
    digitalwrite(set2back, LOW);
    delay(1);
    // Next step
    digitalwrite(set1back, HIGH);
    digitalwrite(set2forward, HIGH);
    delay(duration);
    // Delay
    digitalwrite(set1back, LOW);
    digitalwrite(set2forward, LOW);
    delay(1);
}