/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 *
 * debug.h
 */

#ifndef _DEBUG_H
#define _DEBUG_H

#include <stdarg.h>
#include <stdint.h>

#define DEBUG_PRINT_ADDR 0x0A000000

void debug_printf_c(char c);

void debug_printf_s(char *p);

void debug_printf_d(int val);

void debug_printf_x(unsigned long val, unsigned char char_count);

void debug_printf(const char *format, ...);

#endif