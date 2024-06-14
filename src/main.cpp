#include <Arduino.h>

void blinkLED(int potPin, int ledPin);
void offLED(int ledPin);
void checkButton(int buttonPin);
void toggleLED(int potPin, int ledPin);

int ledPin = 4;
int potPin = A1;
int buttonPin = 2;

int minDelay = 50;
int maxDelay = 1000;

bool ledState = false;
bool buttonState = false;
bool lastButtonState = false;

void setup(){

  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop(){

  checkButton(buttonPin);
  toggleLED(potPin, ledPin);

}


void checkButton(int buttonPin){
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState && buttonState == false){
    ledState = !ledState;
    Serial.print("LED state: ");
    Serial.println(ledState ? "ON" : "OFF");
    delay(50);
  }
  lastButtonState = buttonState;
}

void toggleLED(int potPin, int ledPin){
  if (ledState == true){
    blinkLED(potPin, ledPin);
  }
  else if (ledState == false){
    offLED(ledPin);
  }
}

void blinkLED(int potPin, int ledPin){
  int dt = map(analogRead(potPin), 1, 1024, minDelay, maxDelay);
  digitalWrite(ledPin, HIGH);
  delay(dt);
  digitalWrite(ledPin, LOW);
  delay(dt);
}

void offLED(int ledPin){
  digitalWrite(ledPin, LOW);
}

