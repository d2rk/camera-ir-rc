/*
 * Copyright (c) 2014 Oleksandr Sviridenko
 *
 * http://robionica.org/
 */

#ifndef __AVR_INTERFACE_H
#define __AVR_INTERFACE_H

#include <Arduino.h>

/* Returns number of clock cycles per 1 microsecond. */
#define GET_CLOCK_CYCLES_PER_USEC clockCyclesPerMicrosecond

#define DELAY_USEC(n) microsecondsDelay(n)
#define DELAY_CLOCK_CYCLES(cycles) __builtin_avr_delay_cycles(cycles)

#endif  /* __AVR_INTERFACE_H */
