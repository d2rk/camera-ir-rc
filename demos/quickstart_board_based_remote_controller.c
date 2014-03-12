/*
 * QuickStart board based remote controller: connect IR LED to the
 * IR_LED_PIN pin and push button BUTTON_PIN to take a picture.
 *
 * Copyright (c) 2014 Oleksandr Sviridenko
 */

#include "camera_ir_rc/camera_ir_rc.h"
#include "camera_ir_rc/propeller.h"

#define IR_LED_PIN 27
#define BUTTON_PIN 3

#define BUTTON_DELAY 4  /* ms */
#define BUTTON_FINAL_DELAY 100  /* ms */
#define DEBOUNCE_LOOPS 60
#define DEBOUNCE_TOLERANCE 15

char is_button_pressed()
{
	char result;
	char count;
  for (count = 0, result = 0; count < DEBOUNCE_LOOPS; count++) {
    DRIVE_PIN_HIGH(BUTTON_PIN);
    SET_PIN_OUTPUT_DIRECTION(BUTTON_PIN);
    SET_PIN_INPUT_DIRECTION(BUTTON_PIN);
		DELAY_MSEC(BUTTON_DELAY);
    result += GET_PIN_VALUE(BUTTON_PIN);
  }
  DELAY_MSEC(BUTTON_FINAL_DELAY);
  return (result < (DEBOUNCE_LOOPS - DEBOUNCE_TOLERANCE));
}

int main()
{
  while (1) {
		if (is_button_pressed()) {
	    canon_eos_shutter_now(IR_LED_PIN);
		}
  }
  return 0;
}
