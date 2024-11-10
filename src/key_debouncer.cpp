#include "key_debouncer.h"

#include <array>
#include <vector>

static std::vector<KeyDebouncer *> keys;
static hw_timer_t *key_manager_timer;
static bool key_manager_is_set_up;
static std::array<KeyDebouncer *, KEY_DEBOUNCER_GPIO_PINS> keys_for_interrupts;


static void ARDUINO_ISR_ATTR key_interrupt_handler_00() {
  KeyDebouncer *key = keys_for_interrupts[0];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_01() {
  KeyDebouncer *key = keys_for_interrupts[1];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_02() {
  KeyDebouncer *key = keys_for_interrupts[2];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_03() {
  KeyDebouncer *key = keys_for_interrupts[3];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_04() {
  KeyDebouncer *key = keys_for_interrupts[4];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_05() {
  KeyDebouncer *key = keys_for_interrupts[5];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_06() {
  KeyDebouncer *key = keys_for_interrupts[6];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_07() {
  KeyDebouncer *key = keys_for_interrupts[7];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_08() {
  KeyDebouncer *key = keys_for_interrupts[8];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_09() {
  KeyDebouncer *key = keys_for_interrupts[9];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_10() {
  KeyDebouncer *key = keys_for_interrupts[10];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_11() {
  KeyDebouncer *key = keys_for_interrupts[11];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_12() {
  KeyDebouncer *key = keys_for_interrupts[12];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_13() {
  KeyDebouncer *key = keys_for_interrupts[13];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_14() {
  KeyDebouncer *key = keys_for_interrupts[14];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_15() {
  KeyDebouncer *key = keys_for_interrupts[15];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_16() {
  KeyDebouncer *key = keys_for_interrupts[16];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_17() {
  KeyDebouncer *key = keys_for_interrupts[17];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_18() {
  KeyDebouncer *key = keys_for_interrupts[18];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_19() {
  KeyDebouncer *key = keys_for_interrupts[19];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_20() {
  KeyDebouncer *key = keys_for_interrupts[20];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_21() {
  KeyDebouncer *key = keys_for_interrupts[21];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_22() {
  KeyDebouncer *key = keys_for_interrupts[22];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_23() {
  KeyDebouncer *key = keys_for_interrupts[23];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_24() {
  KeyDebouncer *key = keys_for_interrupts[24];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_25() {
  KeyDebouncer *key = keys_for_interrupts[25];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_26() {
  KeyDebouncer *key = keys_for_interrupts[26];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_27() {
  KeyDebouncer *key = keys_for_interrupts[27];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_28() {
  KeyDebouncer *key = keys_for_interrupts[28];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_29() {
  KeyDebouncer *key = keys_for_interrupts[29];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_30() {
  KeyDebouncer *key = keys_for_interrupts[30];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_31() {
  KeyDebouncer *key = keys_for_interrupts[31];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_32() {
  KeyDebouncer *key = keys_for_interrupts[32];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_33() {
  KeyDebouncer *key = keys_for_interrupts[33];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_34() {
  KeyDebouncer *key = keys_for_interrupts[34];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_35() {
  KeyDebouncer *key = keys_for_interrupts[35];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_36() {
  KeyDebouncer *key = keys_for_interrupts[36];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_37() {
  KeyDebouncer *key = keys_for_interrupts[37];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_38() {
  KeyDebouncer *key = keys_for_interrupts[38];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_39() {
  KeyDebouncer *key = keys_for_interrupts[39];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_40() {
  KeyDebouncer *key = keys_for_interrupts[40];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_41() {
  KeyDebouncer *key = keys_for_interrupts[41];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_42() {
  KeyDebouncer *key = keys_for_interrupts[42];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_43() {
  KeyDebouncer *key = keys_for_interrupts[43];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_44() {
  KeyDebouncer *key = keys_for_interrupts[44];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_45() {
  KeyDebouncer *key = keys_for_interrupts[45];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_46() {
  KeyDebouncer *key = keys_for_interrupts[46];
  if (key) key->interrupt();
}

static void ARDUINO_ISR_ATTR key_interrupt_handler_47() {
  KeyDebouncer *key = keys_for_interrupts[47];
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

static void key_manager_interrupt_handler_register(KeyDebouncer *key) {
  keys_for_interrupts[key->pin] = key;
  attachInterrupt(key->pin, key_manager_interrupt_handler[key->pin], CHANGE);
}

static void key_manager_interrupt_handler_unregister(KeyDebouncer *key) {
  detachInterrupt(key->pin);
  keys_for_interrupts[key->pin] = nullptr;
}

static void ARDUINO_ISR_ATTR key_manager_reschedule() {
  uint64_t earliest = -1;
  bool needed = false;
  for (std::vector<KeyDebouncer *>::iterator i = keys.begin(); i < keys.end(); i++) {
    if ((*i)->debouncing) {
      if (earliest > (*i)->validWhen) earliest = (*i)->validWhen;
      needed = true;
    }
    if ((*i)->repeat) {
      if (earliest > (*i)->repeatWhen) earliest = (*i)->repeatWhen;
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
  for (std::vector<KeyDebouncer *>::iterator i = keys.begin(); i < keys.end(); i++) {
    if (now >= (*i)->validWhen) (*i)->isNowValid();
    if ((*i)->repeat && now >= (*i)->repeatWhen) (*i)->actionRepeat();
  }
  key_manager_reschedule();
}

bool key_manager_begin(uint8_t timer) {
  if (key_manager_is_set_up) return true;
  key_manager_timer = timerBegin(timer, KEY_DEBOUNCER_DIVIDER, true);
  if (!key_manager_timer) return false;
  timerAttachInterrupt(key_manager_timer, key_manager_timer_interrupt, false);
  key_manager_is_set_up = true;
  return true;
}

bool key_manager_begin() {
  return key_manager_begin(KEY_DEBOUNCER_DEFAULT_TIMER);
}

static bool key_manager_addKey(KeyDebouncer *key) {
  if (!key_manager_begin()) return false;
  keys.push_back(key);
  key_manager_interrupt_handler_register(key);
  return true;
}

static void key_manager_removeKey(KeyDebouncer *key) {
  key_manager_interrupt_handler_unregister(key);
  for (std::vector<KeyDebouncer *>::iterator i = keys.begin(); i < keys.end(); i++) {
    if (*i == key) keys.erase(i);
  }
  if (!keys.size()) {
    timerDetachInterrupt(key_manager_timer);
    timerEnd(key_manager_timer);
    key_manager_is_set_up = false;
  }
}



KeyDebouncer::KeyDebouncer(uint8_t pin, bool inverseLogic, time_t autoRepeatPeriod, time_t autoRepeatDelay) {
  KeyDebouncer::pin = pin;
  KeyDebouncer::inverseLogic = inverseLogic;
  KeyDebouncer::autoRepeatDelay = autoRepeatDelay;
  KeyDebouncer::autoRepeatPeriod = autoRepeatPeriod;
  KeyDebouncer::debounceTime = KEY_DEBOUNCER_DEFAULT_DEBOUNCE_TIME_US;
}

KeyDebouncer::KeyDebouncer(uint8_t pin, bool inverseLogic) : KeyDebouncer(pin, inverseLogic, 0, 0) {
}

KeyDebouncer::KeyDebouncer(uint8_t pin) : KeyDebouncer(pin, false) {
}

KeyDebouncer::~KeyDebouncer() {
  if (isRegistered) {
    key_manager_removeKey(this);
    isRegistered = false;
  }
}

bool KeyDebouncer::begin() {
  pinMode(pin, inverseLogic ? INPUT_PULLUP : INPUT_PULLDOWN);
  bool currentState = digitalRead(pin);
  state = inverseLogic ? !currentState : currentState;
  isRegistered = true;
  return key_manager_addKey(this);
}

void KeyDebouncer::setDebounceTime(time_t microseconds) {
  debounceTime = microseconds;
}

void KeyDebouncer::callMeIfPressedOnInterrupt(void (*handler)()) {
  callMeIfPressedOnInterruptHandler = handler;
}

void KeyDebouncer::callMeIfReleasedOnInterrupt(void (*handler)()) {
  callMeIfReleasedOnInterruptHandler = handler;
}

void KeyDebouncer::callMeIfPressedOnLoop(void (*handler)()) {
  callMeIfPressedOnLoopHandler = handler;
}

void KeyDebouncer::callMeIfReleasedOnLoop(void (*handler)()) {
  callMeIfReleasedOnLoopHandler = handler;
}

void ARDUINO_ISR_ATTR KeyDebouncer::interrupt() {
  lastInterruptWhen = timerRead(key_manager_timer);
  validWhen = lastInterruptWhen + debounceTime;
  debouncing = true;
  repeat = false;
  interruptCounter++;
  key_manager_reschedule();
}

void ARDUINO_ISR_ATTR KeyDebouncer::action() {
  if (state && callMeIfPressedOnInterruptHandler) (*callMeIfPressedOnInterruptHandler)();
  if (!state && callMeIfReleasedOnInterruptHandler) (*callMeIfReleasedOnInterruptHandler)();
  if (state && callMeIfPressedOnLoopHandler) loopPressed = true;
  if (!state && callMeIfReleasedOnLoopHandler) loopReleased = true;
}

void ARDUINO_ISR_ATTR KeyDebouncer::actionRepeat() {
  action();
  uint64_t now = timerRead(key_manager_timer);
  repeatWhen = now + autoRepeatPeriod;
}

void ARDUINO_ISR_ATTR KeyDebouncer::isNowValid() {
  debouncing = false;
  bool currentState = digitalRead(pin);
  if (inverseLogic) currentState = !currentState;
  if (state != currentState) {
    state = currentState;
    action();
    if (state) {
      if (autoRepeatPeriod) {
        uint64_t now = timerRead(key_manager_timer);
        if (autoRepeatDelay) {
          repeatWhen = now + autoRepeatDelay;
        }
        else {
          repeatWhen = now + autoRepeatPeriod;
        }
        repeat = true;
      }
    }
  }
}

bool KeyDebouncer::isPressed() {
  return state;
}

void KeyDebouncer::loop() {
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
  for (std::vector<KeyDebouncer *>::iterator i = keys.begin(); i < keys.end(); i++) {
    (*i)->loop();
  }
}