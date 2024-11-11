# ESP32 Key Debouncer for Arduino projects
Debounce mechanical keys connected to ESP32/ESP8266 pins and either VCC or GND entirely in software - no additional components needed.

The library supports as many keys as you can connect, it supports calling your event handlers either on the interrupt or on the loop, and it can do automatic key repetition if the key is held (after a certain delay, if you like).

Usage example:

```
#include <KeyDebouncer.h>

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
  KeyDebouncer_loop();
  ...
}
```

You don't have to use the library's ability to call handlers; just poll `myKey.isPressed()` instead if you prefer to make your life miserable.
We all have our fetishs and there's no need to be ashamed.

## Documentation (kind of)

### General set-up

```
  bool KeyDebouncer_begin(uint8_t timer);
  bool KeyDebouncer_begin();
```

Call one of these early in your setup() function. You don't _have_ to, strictly speaking, because it is done automagically for you
when you create your first instance and call its `begin()` method, but if you want control and want to be able to choose the
timer, do it in `setup()`. The default timer for the ESP32 is `3`, but you can use any available timer. The ESP32 has four of them,
numbered 0 to 3. The ESP8266 only has two, and the first timer is needed for wifi so you'll probably want to use timer `1`.
This is also the default.

Return value: `true` if all went well, `false` if not.

```
  void KeyDebouncer_loop();
```

Call this in your `loop()` function. You don't _have_ to, strictly speaking, but if you want to use `callMeIfPressedOnLoop(handler)`
or `callMeIfReleasedOnLoop(handler)`, you must. Just do it. There, that wasn't too bad, was it?

### Constructors

```
  KeyDebouncer(uint8_t pin);
  KeyDebouncer(uint8_t pin, bool inverseLogic);
  KeyDebouncer(uint8_t pin, bool inverseLogic, time_t autoRepeatPeriod, time_t autoRepeatDelay);
```

Creates a key debouncer instance. You need to provide the GPIO pin number, and you may request inverse logic (if your key is wired to GND instead of 3V3).
If you would like the key to auto-repeat, provide the times in microseconds as well.

### Destructor

The `KeyDebouncer` object has a destructor that takes care of everything should you decide that you no longer need it and you `delete` it.
It is safe to just `delete` an instance.

### Methods

```
    bool begin();
    void setDebounceTime(time_t microseconds);
```

Call `begin()` before you do anything else with your newly created instance. If you would like to use a different _debounce time_ that the default 20 milliseconds, call `setDebounceTime(microseconds)` afterwards (or any time later on). Most keys should have settled their state within 20 milliseconds,
and users should not notice this shot delay.

```
    bool isPressed();
```

Poll the current state of the key. No, don't. I mean ... you _can_. But why would you want to, you little pervert?

```
    void callMeIfPressedOnInterrupt(void (*handler)());
    void callMeIfReleasedOnInterrupt(void (*handler)());
    void callMeIfPressedOnLoop(void (*handler)());
    void callMeIfReleasedOnLoop(void (*handler)());
```

This is how you should do it, really (see example at the very beginning). There are two general types of hooks.

The __Interrupt__ versions are called in interrupt context and provide _immediate_ signalling of key state changes,
but of course this means that you are very restricted in the handlers. Please do not use these versions unless you know what you are doing.
You have been warned.

The __Loop__ versions are called in loop context and provide _ASAP_ signalling of key state changes. Unless you have very good reasons
to use the interrupt versions, it is strongly suggested that you use the loop versions.

The __Released__ handlers are always called only once when the key is released. The __Pressed__ handlers are called at least once when the
key is pressed, but may be called several times if you have configured auto repetition and the button is pressed long enough.

Please refrain from calling other public methods that you may find in the header file. It is only in your best interest. Thank you for your cooperation.

### Properties

There are no public properties that you actually need to use, but some may be useful or interesting.

```
    bool state;
    int interruptCounter;
```

Checking `state` is equivalent to calling `isPressed()`. Use whatever you prefer. (Or better, don't. See above.)

`interruptCounter` will tell you how many bounces of your key have been detected since creation of the `KeyDebouncer` instance.
Use it if you want to see how bad your keys are. The worst of them may bounce a hundred times for each press or release.
This does mean of course that pressing or releasing them wastes a certain amount of CPU time, and better keys waste less.

## Limitations

At one point your hardware timers will overflow. This will probably cause problems with key debouncing for a few milliseconds.
On variants with 64 bit counters this will happen every 584,942 years, and on variants with 56 bit counters it's every 2,284 years.
You decide if you care; I don't.

## How it works

The ESP32/ESP8266 has internal pull-up/pull-down resistors on most pins, and we configure them accordingly, so
you just need to wire the key to the GPIO pin and either 3V3 or GND (unless you use a GPIO pin that hasn't got pull-up/pull-down
resistors). We fire up a hardware counter that counts up every microsecond. Each GPIO pin has an interrupt, and we configure it
to fire on every state change. When the interrupt fires, we note the counter state and add the debouncing period to it.
The timer's alarm interrupt is configured to fire when the lowest calculated debouncing period of any key has expired, and if
a key's debouncing period has expired, its state is noted and signalled. In other words: we only use key states that have
been stable for at least the debouncing period. Simple as that!

## Copyright and License

ESP32 Key Debouncer
Copyright (C) 2024 Christian Blum

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

## Contact the author

Just send email to `bastelkeller@pf-b.de`.