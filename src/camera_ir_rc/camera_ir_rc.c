/*
 * Copyright (c) 2014 Oleksandr Sviridenko
 *
 * http://www.robionica.org/
 */

#include "camera_ir_rc.h"
#include "chip_interface.h"

#define PULSOUT_AND_WAIT_X16(pin, clock_cycles) \
  do {                                          \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
    PULSOUT_AND_WAIT(pin, clock_cycles);        \
  } while (0)

void canon_eos_shutter_delayed(int pin)
{
  long clock_cycles = GET_CLOCK_CYCLES_PER_USEC(11);
  SET_PIN_OUTPUT_MODE(pin);
  PULSOUT_AND_WAIT_X16(pin, clock_cycles);
  DELAY_USEC(5360);
  PULSOUT_AND_WAIT_X16(pin, clock_cycles);
}

void canon_eos_shutter_now(int pin)
{
  long clock_cycles = GET_CLOCK_CYCLES_PER_USEC(11);
  SET_PIN_OUTPUT_MODE(pin);
  PULSOUT_AND_WAIT_X16(pin, clock_cycles);
  DELAY_USEC(7330);
  PULSOUT_AND_WAIT_X16(pin, clock_cycles);
}
