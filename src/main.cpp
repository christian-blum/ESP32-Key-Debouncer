#include <Arduino.h>

#include "key.h"

Key key(19, true);

bool lastState;

void setup() {
  Serial.begin(115200);
  key.begin();
  lastState = key.isPressed();
}

void loop() {
  bool state = key.isPressed();
  if (state != lastState) {
    Serial.print(state); Serial.print(" "); Serial.println(key.interruptCounter);
    lastState = state;
  }
}

