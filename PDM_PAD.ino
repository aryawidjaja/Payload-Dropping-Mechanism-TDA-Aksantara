#include <Servo.h>
Servo servo1;
Servo servo2;
int units;
int trigger = 8;
int detector = 7;
int pos = 0;
int sol1 = 3;
int sol2 = 4;
int ledPin = 5;
int button = 6;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(detector,INPUT);
  pinMode(trigger,INPUT);
  pinMode(sol1,OUTPUT);
  pinMode(sol2,OUTPUT);
  pinMode(button,INPUT);
  pinMode(ledPin,OUTPUT);
  servo1.attach(10);
  servo2.attach(11);
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
}

void loop() {
  buttonState = digitalRead(button);
  if (buttonState == HIGH) {
     Serial.println("Manual mode");
     digitalWrite(ledPin, HIGH);
     servo1.writeMicroseconds(1000);
     servo2.writeMicroseconds(2000);
     delay(2000);
     digitalWrite(sol1, HIGH);
     digitalWrite(sol2, HIGH);
     delay(3000);
     digitalWrite(sol1, LOW);
     digitalWrite(sol2, LOW);
     delay(100);
     digitalWrite(ledPin, LOW);
     delay(100);
     digitalWrite(ledPin, HIGH);
     delay(100);
     digitalWrite(ledPin, LOW);
     delay(100);
     digitalWrite(ledPin, HIGH);
     delay(100);
     digitalWrite(ledPin, LOW);
     delay(100);
     digitalWrite(ledPin, HIGH);
     delay(100);
     digitalWrite(ledPin, LOW);
     delay(100);
     digitalWrite(ledPin, HIGH);
     delay(100);
     digitalWrite(ledPin, LOW);
     delay(100);
     digitalWrite(ledPin, HIGH);
     delay(100);
     digitalWrite(ledPin, LOW);
     delay(100);
     digitalWrite(ledPin, HIGH);
     delay(3000);
  }
  else {
    Serial.println("Auto mode");
    digitalWrite(ledPin, LOW);
    servo1.writeMicroseconds(1500);
    servo2.writeMicroseconds(1500);
    if (digitalRead(trigger)==LOW){
      Serial.println("Bay Opened. ");
      servo1.writeMicroseconds(1000);
      servo2.writeMicroseconds(2000);
      delay(500);
      if (digitalRead(detector)==LOW){
        digitalWrite(sol1, HIGH);
        digitalWrite(sol2, HIGH);
        Serial.println("Dropping payload...");
        delay(1000);
        digitalWrite(sol1, LOW);
        digitalWrite(sol2, LOW);
        delay(1500);
      }
      else  {
        digitalWrite(sol1, LOW);
        digitalWrite(sol2, LOW);
        Serial.println("Bay Closed");

        }
    }
  }
}
