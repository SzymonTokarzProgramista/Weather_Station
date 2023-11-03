#include "SevSeg.h"
SevSeg sevseg; 

void setup() {
  Serial.begin(9600);
  byte numDigits = 4;   
  byte digitPins[] = {12, 9, 8, 6};
  byte segmentPins[] = {11, 7, 4, 2, 1, 10, 5, 3};
  bool resistorsOnSegments = true; 
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
}


void loop() {
  int potencjometr = analogRead(A0); 
  potencjometr = map(potencjometr, 0, 1023, 0, 5000); 
  float termometr =((analogRead(A1)* 5.0) / 1024.0) * 100;
  
  sevseg.setNumber(potencjometr, 3);
  sevseg.refreshDisplay();
  Serial.print(termometr);
  
}