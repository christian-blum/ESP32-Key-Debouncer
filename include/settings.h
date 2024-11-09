#ifndef __ESP32_KEY_DEBOUNCER_SETINGS_H
#define __ESP32_KEY_DEBOUNCER_SETINGS_H

#define KEY_DEBOUNCER_TIMER 3
#define KEY_DEBOUNCER_PLL_FREQ 80000000
#define KEY_DEBOUNCER_DIVIDER 80
#define KEY_DEBOUNCER_GPIO_PINS 48  // 00 - 47
#define KEY_DEBOUNCER_DEBOUNCE_TIME_US 20000 // state needs to be stable for 20 ms to make a state change valid

#endif