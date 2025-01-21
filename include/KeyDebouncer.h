#ifndef __ESP32_KEY_DEBOUNCER_KEY_H
#define __ESP32_KEY_DEBOUNCER_KEY_H

#if defined(ESP32)
#if CONFIG_IDF_TARGET_ESP32C3
#define KEY_DEBOUNCER_DEFAULT_TIMER 1
#else
#define KEY_DEBOUNCER_DEFAULT_TIMER 3
#endif
#else
#if defined(ESP8266)
#define KEY_DEBOUNCER_DEFAULT_TIMER 1
#else
#error Unsupported architecture.
#endif
#endif

#define KEY_DEBOUNCER_DIVIDER 80
#define KEY_DEBOUNCER_GPIO_PINS 48  // 00 - 47
#define KEY_DEBOUNCER_DEFAULT_DEBOUNCE_TIME_US 20000 // state needs to be stable for 20 ms to make a state change valid

#include <Arduino.h>

bool KeyDebouncer_begin(uint8_t timer);
bool KeyDebouncer_begin();
void KeyDebouncer_loop();

class KeyDebouncer {
  protected:
    bool isRegistered = false;
    bool inverseLogic = false;
    time_t debounceTime = 0;
    uint64_t lastInterruptWhen = 0;
    void (*callMeIfPressedOnInterruptHandler)() = nullptr;
    void (*callMeIfLongPressedOnInterruptHandler)() = nullptr;
    void (*callMeIfReleasedOnInterruptHandler)() = nullptr;
    void (*callMeIfPressedOnLoopHandler)() = nullptr;
    void (*callMeIfLongPressedOnLoopHandler)() = nullptr;
    void (*callMeIfReleasedOnLoopHandler)() = nullptr;
    volatile bool loopPressed = false;
    volatile bool loopReleased = false;
    volatile bool loopLongPressed = false;

    time_t autoRepeatDelay = 0;
    time_t autoRepeatPeriod = 0;
    time_t longPressedDelay = 0;

    void action();

  public:
    KeyDebouncer(uint8_t pin);
    KeyDebouncer(uint8_t pin, bool inverseLogic, time_t autoRepeatPeriod = 0, time_t autoRepeatDelay = 0, time_t longPressedDelay = 0);
    ~KeyDebouncer();

    bool begin();
    void setDebounceTime(time_t microseconds);
    bool isPressed();
    void callMeIfPressedOnInterrupt(void (*handler)());
    void callMeIfLongPressedOnInterrupt(void (*handler)());
    void callMeIfReleasedOnInterrupt(void (*handler)());
    void callMeIfPressedOnLoop(void (*handler)());
    void callMeIfLongPressedOnLoop(void (*handler)());
    void callMeIfReleasedOnLoop(void (*handler)());

    // don't call any of these
    void interrupt();
    void isNowValid();
    void loop();
    void actionRepeat();
    void actionLongPressed();

    // It's okay to sneak but don't modify please
    bool debouncing = false;
    int8_t pin = -1;
    bool state = false;
    bool repeat = false;
    uint64_t validWhen = 0;
    uint64_t repeatWhen = 0;
    uint64_t longPressedWhen = 0;
    int interruptCounter = 0;
};

#endif