/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 *
 * debug.c
 */

#include <stdlib.h>
#include "../include/debug.h"

void debug_printf_c(char  c) {
  *((volatile char*)DEBUG_PRINT_ADDR) = c;
}

void debug_printf_s(char *p) {
  while (*p)
    *((volatile char*)DEBUG_PRINT_ADDR) = *(p++);
}

void debug_printf_x(unsigned long val, unsigned char char_count){
  unsigned char count = 0;
  char result[9]; // for 32 bit input: 8 hex characters + '\0'
  char hex;

  // get every hex characters from lsb to msb
  while (val > 0) {
    hex = val & 0x0000000f;
    if (hex < 10) { // from '0' to '9'
      hex += '0';
    } else { // from 'a' to 'f'
      hex += 'a' - 0xa;
    }
    result[count] = hex;
    count ++;
    val >>= 4; 
  }

  // print zeroes 
  if (char_count > 0) {
    for (unsigned char i = 0 ; i < char_count - count ; i++) {
      debug_printf_c('0');
    }
  }

  // prints hex characters in reverse order: from msb to lsb
  while (count > 0) {
    debug_printf_c(result[count-1]);
    count--; 
  }
}

void debug_printf_d(int val) {
  char buffer[32];
  char *p = buffer;
  if (val < 0) {
    debug_printf_c('-');
    val = -val;
  }
  while (val || p == buffer) {
    *(p++) = '0' + val % 10;
    val = val / 10;
  }
  while (p != buffer)
    debug_printf_c(*(--p));
}

void debug_printf(const char *format, ...) {
  int i;
  va_list ap;

  va_start(ap, format);

  for (i = 0; format[i]; i++)
    if (format[i] == '%') {
      while (format[++i]) {
      if (format[i] == 'c') {
        debug_printf_c(va_arg(ap,int));
        break;
      }
      if (format[i] == 's') {
        debug_printf_s(va_arg(ap,char*));
        break;
      }
      if (format[i] == 'd') {
        debug_printf_d(va_arg(ap,int));
        break;
      }
      if (format[i] == 'x') {
        debug_printf_x(va_arg(ap,int), 8);
        break;
      }
      }
    } else {
      debug_printf_c(format[i]);
    }
  va_end(ap);
}