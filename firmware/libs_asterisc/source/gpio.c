/*
 * Copyright(C) 2021 by Jeremie Crenne. All rights reserved.
 *
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jeremie Crenne. This copyright must be retained at all times.
 *
 * gpio.h
 */

#include "../include/gpio.h" 

// new version:
// 2 instructions faster, 22 instructions lighter
void pinMode(unsigned long pin, enum pinmode_e mode) {
  unsigned long mask = (1 << pin);
  *gpio_output_en   = (mode == OUTPUT)            ? *gpio_output_en   | mask : *gpio_output_en   & ~mask;
  *gpio_pullup_en   = (mode == INPUT_PULLUP)      ? *gpio_pullup_en   | mask : *gpio_pullup_en   & ~mask;
  *gpio_pulldown_en = (mode == INPUT_PULLDOWN)    ? *gpio_pulldown_en | mask : *gpio_pulldown_en & ~mask;
  *iof_sel          = (mode == HARDWARE_FUNCTION) ? *iof_sel          | mask : *iof_sel          & ~mask;
}
/*
void pinMode(unsigned long pin, enum pinmode_e mode) {
  unsigned long mask = (1 << pin);
  if (mode == INPUT) {
    *gpio_output_en   &= ~mask;
    *gpio_pulldown_en &= ~mask;
    *gpio_pullup_en   &= ~mask;
    *iof_sel          &= ~mask;
  } else if (mode == INPUT_PULLUP) {
    *gpio_output_en   &= ~mask;
    *gpio_pullup_en   |=  mask;
    *gpio_pulldown_en &= ~mask;
    *iof_sel          &= ~mask;
  } else if (mode == INPUT_PULLDOWN) {
    *gpio_output_en   &= ~mask;
    *gpio_pullup_en   &= ~mask;
    *gpio_pulldown_en |=  mask;
    *iof_sel          &= ~mask;
  } else if (mode == OUTPUT) {
    *gpio_output_en   |=  mask;
    *gpio_pulldown_en &= ~mask;
    *gpio_pullup_en   &= ~mask;
    *iof_sel          &= ~mask;
  } else if (mode == HARDWARE_FUNCTION) {
    *gpio_output_en   &= ~mask;
    *gpio_pulldown_en &= ~mask;
    *gpio_pullup_en   &= ~mask;
    *iof_sel          |=  mask;
  } else {
    *gpio_output_en   &= ~mask;
    *gpio_pulldown_en &= ~mask;
    *gpio_pullup_en   &= ~mask;
    *iof_sel          &= ~mask;
  }
}
*/

unsigned char digitalRead(unsigned long pin) {
  return (*gpio_read_value & (1 << pin)) >> pin;
}

void digitalWrite(unsigned long pin, unsigned char value) {
  *gpio_write_value = (value == LOW) ? *gpio_write_value & ~(1 << pin) : *gpio_write_value | (1 << pin);
}

