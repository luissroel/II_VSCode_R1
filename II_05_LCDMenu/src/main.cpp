#include <Arduino.h>
//Rutina antirebote
#define LED 13
#define button 6

int outputState;
int outputLED;
int LEDStatus;
int counter;


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  int currentState = digitalRead(button);
  delay(15);
  if (currentState == HIGH){
    outputState = 1;
  }

  if(outputState == 1 && currentState == LOW){
    outputLED =! outputLED;
    digitalWrite(LED, outputLED);
    Serial.println(counter++);
    outputState = 0;
  }
}