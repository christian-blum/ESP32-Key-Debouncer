#ifndef __ESP32_KEY_DEBOUNCER_KEY_H
#define __ESP32_KEY_DEBOUNCER_KEY_H

#include <Arduino.h>

class Key {
  private:
    bool isRegistered;
    bool inverseLogic;
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

  public:
    Key(uint8_t pin);
    Key(uint8_t pin, bool inverseLogic);
    Key(uint8_t pin, bool inverseLogic, time_t autoRepeatDelay, time_t autoRepeatPeriod);
    ~Key();

    bool begin();
    bool isPressed();
    void callMeIfPressedOnInterrupt(void (*handler)());
    void callMeIfReleasedOnInterrupt(void (*handler)());
    void callMeIfPressedOnLoop(void (*handler)());
    void callMeIfReleasedOnLoop(void (*handler)());

    // don't call any of these
    void interrupt();
    void isNowValid();
    void loop();

    // It's okay to sneak but don't modify please
    bool debouncing;
    uint8_t pin;
    bool state;
    int64_t validWhen;
    int interruptCounter;
};

void key_loop();

#endif