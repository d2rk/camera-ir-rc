/*
 * Copyright (c) 2014 Oleksandr Sviridenko
 *
 * http://www.robionica.org/
 */

#ifndef __CHIP_INTERFACE_H
#define __CHIP_INTERFACE_H

#ifdef __PROPELLER__
#include "propeller_interface.h"
#else
#error This chip is not supported yet.
#endif

#define PULSOUT(pin, clock_cycles)                         \
  do {                                                     \
    DRIVE_PIN_HIGH(pin);                                   \
    DELAY_CLOCK_CYCLES(clock_cycles);                      \
    DRIVE_PIN_LOW(pin);                                    \
  } while (0)

#define PULSOUT_AND_WAIT(pin, clock_cycles)                \
  do {                                                     \
    PULSOUT(pin, clock_cycles);                            \
    DELAY_CLOCK_CYCLES(clock_cycles);                      \
  } while (0)

#endif  /* __CHIP_INTERFACE_H */
