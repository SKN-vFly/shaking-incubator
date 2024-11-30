const int out1pin = 12;
const int out2pin = 13;
const int out3pin = 10;
const int out4pin = 11;
bool play = true;
const int DELAY = 10;
unsigned long previousMillis = 0;
unsigned long period = 1000;
void setup() {
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
    period = inp.toInt();
  }
  Serial.println(period);

  if (currentMillis - previousMillis >= period) {
     pulse_full(period/2);
     previousMillis = currentMillis;
  }
}

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
