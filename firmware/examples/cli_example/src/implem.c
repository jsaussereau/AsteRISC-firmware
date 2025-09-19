/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 * 
 * implem.c
 */

#include "implem.h" 

void my_puts(const char* str) {
 uart0_puts(str);
}

int my_putchar(char c) {
  return uart0_putchar(c);
}

char my_getchar() {
  return uart0_getchar();
}