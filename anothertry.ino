const int out1pin = 10;
const int out2pin = 11;
const int out3pin = 13;
const int out4pin = 12;
 // the number of the LED pin
int phaseState = LOW;  // ledState used to set the LED
unsigned long previousMillis = 0;  // will store last time LED was updated
long interval = 1000;  // interval at which to blink (milliseconds)
int sensorValue = 0;
void setup() {
  // set the digital pin as output:
  pinMode(out1pin, OUTPUT);
  pinMode(out2pin, OUTPUT);
  pinMode(out3pin, OUTPUT);
  pinMode(out4pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  if(Serial.available()>0){
    String inp = Serial.readStringUntil('\n');
    sensorValue = inp.toInt();
  }
  Serial.println(sensorValue);
  interval = sensorValue;
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (phaseState == LOW) {
      phaseState = HIGH;
    } else {
      phaseState = LOW;
    }
    digitalWrite(out1pin, phaseState);
    digitalWrite(out2pin, !phaseState);
    digitalWrite(out3pin, phaseState);
    digitalWrite(out4pin, !phaseState);
  }
}