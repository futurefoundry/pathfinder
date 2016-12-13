/*

PathFinder

Last modified on December 13, 2016 by
Mustafa Lokhandwala, Future Foundry. 

*/

#include <NewPing.h>

#define TRIGGER_PIN   12 // Arduino pin tied to trigger pin on ping sensor.
#define ECHO_PIN      11 // Arduino pin tied to echo pin on ping sensor.

int currentResult;

NewPing sonar(TRIGGER_PIN, ECHO_PIN); // NewPing setup of pins and maximum distance.

void setup() {
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(7, LOW);
  analogWrite(10, 190);
}

void loop() {
  currentResult = sonar.ping_cm();
  
  analogWrite(10, 255);
  delay(100);
  
  if (currentResult<=300 && currentResult>0) 
  {
      analogWrite(10, 0);
      delay(currentResult*5);
  }

}
