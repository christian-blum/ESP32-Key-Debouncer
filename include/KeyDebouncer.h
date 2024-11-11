#ifndef __ESP32_KEY_DEBOUNCER_KEY_H
#define __ESP32_KEY_DEBOUNCER_KEY_H

#define KEY_DEBOUNCER_DEFAULT_TIMER 3
#define KEY_DEBOUNCER_DIVIDER 80
#define KEY_DEBOUNCER_GPIO_PINS 48  // 00 - 47
#define KEY_DEBOUNCER_DEFAULT_DEBOUNCE_TIME_US 20000 // state needs to be stable for 20 ms to make a state change valid

#include <Arduino.h>

bool KeyDebouncer_begin(uint8_t timer);
bool KeyDebouncer_begin();
void KeyDebouncer_loop();

class KeyDebouncer {
  private:
    bool isRegistered;
    bool inverseLogic;
    time_t debounceTime;
    uint64_t lastInterruptWhen;
    void (*callMeIfPressedOnInterruptHandler)();
    void (*callMeIfReleasedOnInterruptHandler)();
    void (*callMeIfPressedOnLoopHandler)();
    void (*callMeIfReleasedOnLoopHandler)();
    volatile bool loopPressed;
    volatile bool loopReleased;

    /* not yet implemented */
    time_t autoRepeatDelay;
    time_t autoRepeatPeriod;

    void action();

  public:
    KeyDebouncer(uint8_t pin);
    KeyDebouncer(uint8_t pin, bool inverseLogic);
    KeyDebouncer(uint8_t pin, bool inverseLogic, time_t autoRepeatPeriod, time_t autoRepeatDelay);
    ~KeyDebouncer();

    bool begin();
    void setDebounceTime(time_t microseconds);
    bool isPressed();
    void callMeIfPressedOnInterrupt(void (*handler)());
    void callMeIfReleasedOnInterrupt(void (*handler)());
    void callMeIfPressedOnLoop(void (*handler)());
    void callMeIfReleasedOnLoop(void (*handler)());

    // don't call any of these
    void interrupt();
    void isNowValid();
    void loop();
    void actionRepeat();

    // It's okay to sneak but don't modify please
    bool debouncing;
    uint8_t pin;
    bool state;
    bool repeat;
    uint64_t validWhen;
    uint64_t repeatWhen;
    int interruptCounter;
};

#endif