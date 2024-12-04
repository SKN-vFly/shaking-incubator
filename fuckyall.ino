#include <Arduino.h>

const int set1forward = 12;
const int set1back = 13;
const int set2forward = 11;
const int set2back = 10;
const int duration = 450;


void setup(){
    pinMode(set1forward, OUTPUT);
    pinMode(set1back, OUTPUT);
    pinMode(set2forward, OUTPUT);
    pinMode(set2back, OUTPUT);
    pinMode(A0, INPUT);
    digitalWrite(set1forward, LOW);
    digitalWrite(set1back, HIGH);
    digitalWrite(set2forward, LOW);
    digitalWrite(set2back, HIGH);
    delay(1000);
    digitalWrite(set1back, LOW);
    digitalWrite(set2back, LOW);
    Serial.begin(9600);
}

#define N 5
#define N1 (N+1)

void loop(){
    // Begin   
    digitalWrite(set1back, LOW);
    digitalWrite(set2back, LOW);
    //Serial.println(analogRead(A0));
    delay(duration/N*3);
    digitalWrite(set1forward, HIGH);
    digitalWrite(set2forward, HIGH);
    delay(duration/N1*N);
    // Delay
    digitalWrite(set1forward, LOW);
    digitalWrite(set2forward, LOW);
    delay(100);
    delay(duration/N*3);
    digitalWrite(set1back, HIGH);
    digitalWrite(set2back, HIGH);
    delay(duration/N1*N);
    digitalWrite(set1back, LOW);
    digitalWrite(set2back, LOW);
}