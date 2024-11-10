# ESP32 Key Debouncer for Arduino projects
Debounce mechanical keys connected to ESP32/ESP8266 pins and either VCC or GND entirely in software - no additional components needed.

The library supports as many keys as you can connect, it supports calling your event handlers either on the interrupt or on the loop, and it can do automatic key repetition if the key is held (after a certain delay, if you like).

Usage example:
```
#include <key_debouncer.h>

KeyDebouncer myKey(19, true); // Key connected to GPIO19 and GND
// KeyDebouncer myKey(19, false); // Key connected to GPIO19 and VCC
// KeyDebouncer myKey(19, true, 100000, 200000); // Key connected to GPIO19 and GND, auto-repeat 10 times per second after 200 milliseconds delay

void key_pressed() {
  Serial.println("key pressed");
}

void setup() {
  ...
  myKey.begin();
  myKey.callMeWhenPressedOnLoop(key_pressed);
  ...
}

void loop() {
  ...
  key_debouncer_loop();
  ...
}
```

You don't have to use the library's ability to call handlers; just poll `myKey.isPressed()` instead if you prefer to make your life miserable.
