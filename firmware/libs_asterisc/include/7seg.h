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


#ifndef _7SEG_LIB_H_
#define _7SEG_LIB_H_ 

#include "asterisc.h"
#include "gpio.h" 

/* 
seven segment display format: [A B C D E F G P]
   -------                   MSB             LSB
   |  A  |
 F |     | B
   -------
   |  G  |
 E |     | C
   -------
      D
*/

typedef union {
  struct {
    unsigned char point                   : 1;
    unsigned char seg_G                   : 1;
    unsigned char seg_F                   : 1;
    unsigned char seg_E                   : 1;
    unsigned char seg_D                   : 1;
    unsigned char seg_C                   : 1;
    unsigned char seg_B                   : 1;
    unsigned char seg_A                   : 1;
  };
  struct {
    unsigned char value                   : 8;
  };
} seven_segment_t;

seven_segment_t get_7seg_value(unsigned char input);

#endif // _7SEG_LIB_H_