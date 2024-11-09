#ifndef __KEY_MANAGER_INTERRUPT_HANDLERS_H
#define __KEY_MANAGER_INTERRUPT_HANDLERS_H

#include "key.h"

void key_manager_interrupt_handler_register(Key *key);
void key_manager_interrupt_handler_unregister(Key *key);

#endif