/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 *
 * uart.c
 */


#ifndef _UART_LIB_H_
#define _UART_LIB_H_ 

#include "asterisc.h" 
#include <stddef.h>
#include <stdlib.h>

#define GET_BAUDRATE_DIV(GBD_BAUDRATE, GBD_FREQUENCY) ((GBD_FREQUENCY) / (1 + (GBD_BAUDRATE)))

// Usual Baudrates (All supported at 100 MHz):
#define BAUD_2400    2400  
#define BAUD_4800    4800  
#define BAUD_9600    9600  
#define BAUD_19200   19200 
#define BAUD_38400   38400 
#define BAUD_57600   57600 
#define BAUD_115200  115200
#define BAUD_230400  230400
#define BAUD_460800  460800
#define BAUD_570600  570600
#define BAUD_921600  921600
#define BAUD_1000000 1000000
#define BAUD_2000000 2000000

void _putchar(char c);

int uart0_putchar(int c);

char uart0_getchar();

int uart0_puts(const char *s);

void itoa_light(unsigned long val, char *dest);

int my_strcmp(const char *a, const char *b);

unsigned char is_delim(char c, char *delim);

char* my_strtok(char *s, char *delim);

unsigned short get_baudrate_div(unsigned short baudrate, unsigned long frequency);

#endif // _UART_LIB_H_