#pragma once
#include <stdint.h>

#define PIT_FREQUENCY 1000

void pit_init();
void pit_set_frequency(uint32_t frequency);
void pit_handler();
uint32_t pit_get_ticks();
void pit_sleep(uint32_t milliseconds);