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
    bool isRegistered;
    bool inverseLogic;
    time_t debounceTime;
    uint64_t lastInterruptWhen;
    void (*callMeIfPressedOnInterruptHandler)();
    void (*callMeIfLongPressedOnInterruptHandler)();
    void (*callMeIfReleasedOnInterruptHandler)();
    void (*callMeIfPressedOnLoopHandler)();
    void (*callMeIfLongPressedOnLoopHandler)();
    void (*callMeIfReleasedOnLoopHandler)();
    volatile bool loopPressed;
    volatile bool loopReleased;
    volatile bool loopLongPressed;

    /* not yet implemented */
    time_t autoRepeatDelay;
    time_t autoRepeatPeriod;
    time_t longPressedDelay;

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
    bool debouncing;
    uint8_t pin;
    bool state;
    bool repeat;
    uint64_t validWhen;
    uint64_t repeatWhen;
    uint64_t longPressedWhen;
    int interruptCounter;
};

#endif