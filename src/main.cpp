#include <Arduino.h>

#include "MultiSegmentDisplay/MultiSegmentDisplay.cpp"

#define CLOCK_PIN 4
#define STORAGE_PIN 3
#define DATA_PIN 2

#define ADD_BTN 8
#define SUB_BTN 9

byte count = 24;

void setup() 
{
  Serial.begin(9600);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(STORAGE_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);

  pinMode(ADD_BTN, INPUT);
  pinMode(SUB_BTN, INPUT);
}

void loop() 
{
  digitalWrite(STORAGE_PIN, LOW);

  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, count);

  digitalWrite(STORAGE_PIN, HIGH);
}