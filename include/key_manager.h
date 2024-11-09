#ifndef __ESP32_KEY_DEBOUNCER_KEY_MANAGER_H
#define __ESP32_KEY_DEBOUNCER_KEY_MANAGER_H

#include <vector>
#include "key.h"

extern std::vector<Key *> keys;
extern hw_timer_t *key_manager_timer;

bool key_manager_begin();
bool key_manager_addKey(Key *key);
void key_manager_removeKey(Key *key);
void ARDUINO_ISR_ATTR key_manager_reschedule();

#endif