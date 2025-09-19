/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 *
 * gpio.h
 */


#ifndef _GPIO_LIB_H_
#define _GPIO_LIB_H_ 

#include "asterisc.h" 

#define LOW  0
#define HIGH 1

enum pinmode_e {
   INPUT,
   OUTPUT,
   INPUT_PULLUP,
   INPUT_PULLDOWN,
   HARDWARE_FUNCTION
};

void pinMode(unsigned long pin, enum pinmode_e mode);
void digitalWrite(unsigned long pin, unsigned char value);
unsigned char digitalRead(unsigned long pin);

#endif // _GPIO_LIB_H_