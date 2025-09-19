/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 * 
 * implem.h
 */

#ifndef _CLI_IMPLEM_H_
#define _CLI_IMPLEM_H_ 

#include <uart.h>

void my_puts(const char* str);

int my_putchar(char c);

char my_getchar();

#endif // _CLI_IMPLEM_H_