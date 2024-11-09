#include "key.h"
#include "settings.h"

#include <array>
#include <vector>

static std::vector<Key *> keys;
static hw_timer_t *key_manager_timer;
static bool key_manager_is_set_up;
static std::array<Key *, KEY_DEBOUNCER_GPIO_PINS> keys_for_interrupts;





static void ARDUINO_ISR_ATTR key_interrupt_handler_00() {
  Key *key = keys_for_interrupts[0];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_01() {
  Key *key = keys_for_interrupts[1];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_02() {
  Key *key = keys_for_interrupts[2];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_03() {
  Key *key = keys_for_interrupts[3];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_04() {
  Key *key = keys_for_interrupts[4];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_05() {
  Key *key = keys_for_interrupts[5];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_06() {
  Key *key = keys_for_interrupts[6];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_07() {
  Key *key = keys_for_interrupts[7];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_08() {
  Key *key = keys_for_interrupts[8];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_09() {
  Key *key = keys_for_interrupts[9];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_10() {
  Key *key = keys_for_interrupts[10];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_11() {
  Key *key = keys_for_interrupts[11];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_12() {
  Key *key = keys_for_interrupts[12];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_13() {
  Key *key = keys_for_interrupts[13];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_14() {
  Key *key = keys_for_interrupts[14];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_15() {
  Key *key = keys_for_interrupts[15];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_16() {
  Key *key = keys_for_interrupts[16];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_17() {
  Key *key = keys_for_interrupts[17];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_18() {
  Key *key = keys_for_interrupts[18];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_19() {
  Key *key = keys_for_interrupts[19];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_20() {
  Key *key = keys_for_interrupts[20];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_21() {
  Key *key = keys_for_interrupts[21];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_22() {
  Key *key = keys_for_interrupts[22];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_23() {
  Key *key = keys_for_interrupts[23];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_24() {
  Key *key = keys_for_interrupts[24];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_25() {
  Key *key = keys_for_interrupts[25];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_26() {
  Key *key = keys_for_interrupts[26];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_27() {
  Key *key = keys_for_interrupts[27];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_28() {
  Key *key = keys_for_interrupts[28];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_29() {
  Key *key = keys_for_interrupts[29];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_30() {
  Key *key = keys_for_interrupts[30];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_31() {
  Key *key = keys_for_interrupts[31];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_32() {
  Key *key = keys_for_interrupts[32];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_33() {
  Key *key = keys_for_interrupts[33];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_34() {
  Key *key = keys_for_interrupts[34];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_35() {
  Key *key = keys_for_interrupts[35];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_36() {
  Key *key = keys_for_interrupts[36];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_37() {
  Key *key = keys_for_interrupts[37];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_38() {
  Key *key = keys_for_interrupts[38];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_39() {
  Key *key = keys_for_interrupts[39];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_40() {
  Key *key = keys_for_interrupts[40];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_41() {
  Key *key = keys_for_interrupts[41];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_42() {
  Key *key = keys_for_interrupts[42];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_43() {
  Key *key = keys_for_interrupts[43];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_44() {
  Key *key = keys_for_interrupts[44];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_45() {
  Key *key = keys_for_interrupts[45];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_46() {
  Key *key = keys_for_interrupts[46];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_47() {
  Key *key = keys_for_interrupts[47];
  if (key) key->interrupt();
}

static void (*key_manager_interrupt_handler[KEY_DEBOUNCER_GPIO_PINS])() = {
  key_interrupt_handler_00,
  key_interrupt_handler_01,
  key_interrupt_handler_02,
  key_interrupt_handler_03,
  key_interrupt_handler_04,
  key_interrupt_handler_05,
  key_interrupt_handler_06,
  key_interrupt_handler_07,
  key_interrupt_handler_08,
  key_interrupt_handler_09,
  key_interrupt_handler_10,
  key_interrupt_handler_11,
  key_interrupt_handler_12,
  key_interrupt_handler_13,
  key_interrupt_handler_14,
  key_interrupt_handler_15,
  key_interrupt_handler_16,
  key_interrupt_handler_17,
  key_interrupt_handler_18,
  key_interrupt_handler_19,
  key_interrupt_handler_20,
  key_interrupt_handler_21,
  key_interrupt_handler_22,
  key_interrupt_handler_23,
  key_interrupt_handler_24,
  key_interrupt_handler_25,
  key_interrupt_handler_26,
  key_interrupt_handler_27,
  key_interrupt_handler_28,
  key_interrupt_handler_29,
  key_interrupt_handler_30,
  key_interrupt_handler_31,
  key_interrupt_handler_32,
  key_interrupt_handler_33,
  key_interrupt_handler_34,
  key_interrupt_handler_35,
  key_interrupt_handler_36,
  key_interrupt_handler_37,
  key_interrupt_handler_38,
  key_interrupt_handler_39,
  key_interrupt_handler_40,
  key_interrupt_handler_41,
  key_interrupt_handler_42,
  key_interrupt_handler_43,
  key_interrupt_handler_44,
  key_interrupt_handler_45,
  key_interrupt_handler_46,
  key_interrupt_handler_47
};

static void key_manager_interrupt_handler_register(Key *key) {
  keys_for_interrupts[key->pin] = key;
  attachInterrupt(key->pin, key_manager_interrupt_handler[key->pin], CHANGE);
}

static void key_manager_interrupt_handler_unregister(Key *key) {
  detachInterrupt(key->pin);
  keys_for_interrupts[key->pin] = nullptr;
}

static void ARDUINO_ISR_ATTR key_manager_reschedule() {
  uint64_t earliest = -1;
  bool needed = false;
  for (std::vector<Key *>::iterator i = keys.begin(); i < keys.end(); i++) {
    if ((*i)->debouncing) {
      if (earliest > (*i)->validWhen) earliest = (*i)->validWhen;
      needed = true;
    }
  }
  if (needed) {
    timerAlarmDisable(key_manager_timer);
    timerAlarmWrite(key_manager_timer, earliest, false);
    timerAlarmEnable(key_manager_timer);
  }
  else {
    timerAlarmDisable(key_manager_timer);
  }
}

static void ARDUINO_ISR_ATTR key_manager_timer_interrupt() {
  uint64_t now = timerRead(key_manager_timer);
  for (std::vector<Key *>::iterator i = keys.begin(); i < keys.end(); i++) {
    if (now >= (*i)->validWhen) (*i)->isNowValid();
  }
  key_manager_reschedule();
}

static bool key_manager_begin() {
  key_manager_timer = timerBegin(KEY_DEBOUNCER_TIMER, KEY_DEBOUNCER_DIVIDER, true);
  if (!key_manager_timer) return false;
  timerAttachInterrupt(key_manager_timer, key_manager_timer_interrupt, false);
  key_manager_is_set_up = true;
  return true;
}

static bool key_manager_addKey(Key *key) {
  if (!key_manager_is_set_up) {
    if (!key_manager_begin()) return false;
  }
  keys.push_back(key);
  key_manager_interrupt_handler_register(key);
  return true;
}

static void key_manager_removeKey(Key *key) {
  key_manager_interrupt_handler_unregister(key);
  for (std::vector<Key *>::iterator i = keys.begin(); i < keys.end(); i++) {
    if (*i == key) keys.erase(i);
  }
}



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

void Key::callMeIfPressedOnInterrupt(void (*handler)()) {
  callMeIfPressedOnInterruptHandler = handler;
}

void Key::callMeIfReleasedOnInterrupt(void (*handler)()) {
  callMeIfReleasedOnInterruptHandler = handler;
}

void Key::callMeIfPressedOnLoop(void (*handler)()) {
  callMeIfPressedOnLoopHandler = handler;
}

void Key::callMeIfReleasedOnLoop(void (*handler)()) {
  callMeIfReleasedOnLoopHandler = handler;
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
    if (currentState && callMeIfPressedOnInterruptHandler) (*callMeIfPressedOnInterruptHandler)();
    if (!currentState && callMeIfReleasedOnInterruptHandler) (*callMeIfReleasedOnInterruptHandler)();
    if (currentState && callMeIfPressedOnLoopHandler) loopPressed = true;
    if (!currentState && callMeIfReleasedOnLoopHandler) loopReleased = true;
  }
}

bool Key::isPressed() {
  return state;
}

void Key::loop() {
  if (loopPressed) {
    callMeIfPressedOnLoopHandler();
    loopPressed = false;
  }
  if (loopReleased) {
    callMeIfReleasedOnLoopHandler();
    loopReleased = false;
  }
}


void key_loop() {
  for (std::vector<Key *>::iterator i = keys.begin(); i < keys.end(); i++) {
    (*i)->loop();
  }
}