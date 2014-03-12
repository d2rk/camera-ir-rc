/*
 * Copyright (c) 2014 Oleksandr Sviridenko
 *
 * http://www.robionica.org/
 */

#ifndef __PROPELLER_INTERFACE_H
#define __PROPELLER_INTERFACE_H

#include <propeller.h>

#define GET_CLOCK_FREQUENCY() CLKFREQ

#define SET_PIN_OUTPUT_MODE(pin) DIRA |= 1 << (pin)
#define SET_PIN_INPUT_MODE(pin) DIRA &= ~(1 << (pin))
#define GET_PIN_VALUE(pin) ((INA >> (pin)) & 1)

#define DRIVE_PIN_HIGH(pin) OUTA |= 1 << (pin)
#define DRIVE_PIN_LOW(pin) OUTA &= ~(1 << (pin))

/* Delay for n microseconds. */
#define DELAY_USEC(n) waitcnt(((GET_CLOCK_FREQUENCE() / 1000000) * (n)) + CNT)

/* Delay for n milliseconds. */
#define DELAY_MSEC(n) waitcnt((CLKFREQ / 1000) * (n) + CNT)

/* Delay for n clock cycles. */
#define DELAY_CLOCK_CYCLES(n) waitcnt((n) + CNT)

/* Returns number of clock cycles per 1 microsecond. */
#define GET_CLOCK_CYCLES_PER_USEC(n) ((GET_CLOCK_FREQUENCY() / 1000000) * (n))

#endif  /* __PROPELLER_INTERFACE_H */
