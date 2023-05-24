#include <Servo.h>
#include "HX711.h"
#define DOUT 3
#define CLK 2
#define servo1Pin 10
#define servo2Pin 11
Servo servo1;
Servo servo2;
HX711 scale;
float calibration_factor = -498; // Change this calib factor depends on your HX711 Module
int units;
int motor1pin1 = 4;
int motor1pin2 = 5;
int Reed = 7;
int trigger = 8;
int pos = 0;
const int ENA = 6;

void setup() {
  scale.begin(DOUT, CLK);
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(Reed, INPUT);
  pinMode(trigger, INPUT);
  pinMode(9, OUTPUT);
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  scale.set_scale(calibration_factor);
  scale.tare(); 
  servo1.write(0);
  servo2.write(0);
}

void loop() {
  if (digitalRead(trigger)==LOW){
    analogWrite(ENA, 213  );
    Serial.println("Bay Opened. ");
    servo2.write(100);
    delay(100);
    servo1.write(100);
    delay(300);
    units = scale.get_units(), 5;
    Serial.print(units);
    Serial.print(" grams, ");
    if (units > 100) {
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    Serial.println("Winch down...");
    }
    else {
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
      if (digitalRead(Reed)==LOW){
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);
        Serial.println("Winch fully retracted");
      }
      else {
        Serial.println("Winch up...");
      }
    }
  }
  else  {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    Serial.println("Bay Closed. Winch stopped.");
    servo1.write(0);
    delay(100);
    servo2.write(0);
  }
}
