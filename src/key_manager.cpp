#include "key_manager.h"
#include "key_manager_interrupt_handlers.h"
#include "settings.h"

std::vector<Key *> keys;
hw_timer_t *key_manager_timer;
bool key_manager_is_set_up;


static void ARDUINO_ISR_ATTR key_manager_timer_interrupt() {
  uint64_t now = timerRead(key_manager_timer);
  for (std::vector<Key *>::iterator i = keys.begin(); i < keys.end(); i++) {
    if (now >= (*i)->validWhen) (*i)->isNowValid();
  }
  key_manager_reschedule();
}

bool key_manager_begin() {
  key_manager_timer = timerBegin(KEY_DEBOUNCER_TIMER, KEY_DEBOUNCER_DIVIDER, true);
  if (!key_manager_timer) return false;
  timerAttachInterrupt(key_manager_timer, key_manager_timer_interrupt, false);
  key_manager_is_set_up = true;
  return true;
}

bool key_manager_addKey(Key *key) {
  if (!key_manager_is_set_up) {
    if (!key_manager_begin()) return false;
  }
  keys.push_back(key);
  key_manager_interrupt_handler_register(key);
  return true;
}

void key_manager_removeKey(Key *key) {
  key_manager_interrupt_handler_unregister(key);
  for (std::vector<Key *>::iterator i = keys.begin(); i < keys.end(); i++) {
    if (*i == key) keys.erase(i);
  }
}

void ARDUINO_ISR_ATTR key_manager_reschedule() {
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