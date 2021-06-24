#include "Keyboard.h"

const int ledPin = A3;
const int buttonPin = 8;
const int onPin = A2;
int buttonState = 0; 
int onState = 0;

const int upButton = 10;
const int downButton = 16;
const int leftButton = 14;
const int rightButton = 15;


void setup() {

  Serial.begin(9600);
  pinMode(onPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
}

void loop() {
  onState = digitalRead(onPin);
if (onState == HIGH){
  //-------------------LAZER---------------------------------
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) { 
    digitalWrite(ledPin, HIGH);  
    Serial.println("LED ON +++++++"); 
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF -------");
  }
  //-------------------------------------------------------------------
  if (digitalRead(upButton) == HIGH) {
    Keyboard.write('u');
  }
  if (digitalRead(downButton) == HIGH) {
    Keyboard.write('d');
  }
  if (digitalRead(leftButton) == HIGH) {
    Keyboard.write('l');
  }
  if (digitalRead(rightButton) == HIGH) {
    Keyboard.write('r');
  }
  //-------------------------------------------------------------------
  

  //-----------------------------------------------------------------------
}

}
