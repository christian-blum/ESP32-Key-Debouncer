#include "key.h"
#include "key_manager.h"
#include "settings.h"

Key::Key(uint8_t pin, bool inverseLogic, time_t autoRepeatDelay, time_t autoRepeatPeriod) {
  Key::pin = pin;
  Key::inverseLogic = inverseLogic;
  Key::autoRepeatDelay = autoRepeatDelay;
  Key::autoRepeatPeriod = autoRepeatPeriod;
}

Key::Key(uint8_t pin, bool inverseLogic) : Key(pin, inverseLogic, 0, 0) {
}

Key::Key(uint8_t pin) : Key(pin, false) {
}

Key::~Key() {
  if (isRegistered) {
    key_manager_removeKey(this);
    isRegistered = false;
  }
}

bool Key::begin() {
  pinMode(pin, inverseLogic ? INPUT_PULLUP : INPUT_PULLDOWN);
  bool currentState = digitalRead(pin);
  state = inverseLogic ? !currentState : currentState;
  isRegistered = true;
  return key_manager_addKey(this);
}

void Key::callMeIfPressed(void (*handler)()) {
  callMeIfPressedHandler = handler;
}

void Key::callMeIfReleased(void (*handler)()) {
  callMeIfReleasedHandler = handler;
}

void ARDUINO_ISR_ATTR Key::interrupt() {
  lastInterruptWhen = timerRead(key_manager_timer);
  validWhen = lastInterruptWhen + KEY_DEBOUNCER_DEBOUNCE_TIME_US;
  debouncing = true;
  interruptCounter++;
  key_manager_reschedule();
}

void ARDUINO_ISR_ATTR Key::isNowValid() {
  debouncing = false;
  bool currentState = digitalRead(pin);
  if (inverseLogic) currentState = !currentState;
  if (state != currentState) {
    state = currentState;
    if (currentState && callMeIfPressedHandler) (*callMeIfPressedHandler)();
    if (!currentState && callMeIfReleasedHandler) (*callMeIfReleasedHandler)();
  }
}

bool Key::isPressed() {
  return state;
}