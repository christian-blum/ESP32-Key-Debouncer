#ifndef __ESP32_KEY_DEBOUNCER_KEY_H
#define __ESP32_KEY_DEBOUNCER_KEY_H

#include <Arduino.h>

class Key {
  private:
    bool isRegistered;
    bool inverseLogic;
    uint64_t lastInterruptWhen;
    void (*callMeIfPressedHandler)();
    void (*callMeIfReleasedHandler)();

    /* not yet implemented */
    time_t autoRepeatDelay;
    time_t autoRepeatPeriod;

  public:
    Key(uint8_t pin);
    Key(uint8_t pin, bool inverseLogic);
    Key(uint8_t pin, bool inverseLogic, time_t autoRepeatDelay, time_t autoRepeatPeriod);
    ~Key();

    uint8_t pin;
    bool state;
    bool debouncing;
    int64_t validWhen;
    int interruptCounter;

    bool begin();
    bool isPressed();
    void callMeIfPressed(void (*handler)());
    void callMeIfReleased(void (*handler)());

    // don't call any of these
    void interrupt();
    void isNowValid();

};

#endif