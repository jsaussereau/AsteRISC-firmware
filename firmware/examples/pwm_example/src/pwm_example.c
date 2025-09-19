/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 *
 * pwm_example.c
 */

#include <asterisc.h>
#include <gpio.h>

int _entry() {

  // Set GPIO 0 to 3 as ouputs
  //*iof_sel = 0xf;
  pinMode(0, HARDWARE_FUNCTION);
  pinMode(1, HARDWARE_FUNCTION);
  pinMode(2, HARDWARE_FUNCTION);
  pinMode(3, HARDWARE_FUNCTION);

  // Config reg
  pwm0_config_bits->scale               = 12;
  pwm0_config_bits->sticky              = 0;
  pwm0_config_bits->deglitch            = 1;
  pwm0_config_bits->compare2_complement = 1;
  pwm0_config_bits->zero_cmp            = 1;
  pwm0_config_bits->en_always           = 1;

  // Compare regs
  *pwm0_compare0 = 200;
  *pwm0_compare1 = 100;
  *pwm0_compare2 = *pwm0_compare1;
  *pwm0_compare3 = 150;

  while(1) {
    asm("nop");
  }

  return 0;
}