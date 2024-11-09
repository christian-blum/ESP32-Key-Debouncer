#include <Arduino.h>

#include "key.h"

Key key(19, true);

bool lastState;

static void loopPressed() {
  Serial.println("pressed");
}

static void loopReleased() {
  Serial.println("released");
}

void setup() {
  Serial.begin(115200);
  key.begin();
  lastState = key.isPressed();
  key.callMeIfPressedOnLoop(&loopPressed);
  key.callMeIfReleasedOnLoop(&loopReleased);
}

void loop() {
  bool state = key.isPressed();
  if (state != lastState) {
    Serial.print(state); Serial.print(" "); Serial.println(key.interruptCounter);
    lastState = state;
  }
  key_loop();
}

