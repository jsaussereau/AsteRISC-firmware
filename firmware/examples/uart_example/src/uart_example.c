/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 *
 * uart_example.c
 */

#include <asterisc.h>
#include <gpio.h>
#include <uart.h> 
//#include <printf.h>

#define UART_TX_GPIO 19
#define UART_RX_GPIO 18

#define SWITCH_GPIO 15

#define SWLED_GPIO  7
#define TMLED_GPIO  6

#define TARGET_FREQUENCY 40000000
#define UART_BAUDRATE    BAUD_115200

void init() {
  //gpio config:
  pinMode(TMLED_GPIO, OUTPUT);
  digitalWrite(TMLED_GPIO, HIGH);

  pinMode(SWLED_GPIO, OUTPUT);
  pinMode(SWITCH_GPIO, INPUT);

  pinMode(UART_TX_GPIO, HARDWARE_FUNCTION);
  pinMode(UART_RX_GPIO, HARDWARE_FUNCTION);
  
  // uart config:
  uart0_config_bits->baudrate = GET_BAUDRATE_DIV(UART_BAUDRATE, TARGET_FREQUENCY);
  uart0_config_bits->tx_en = 1;
  uart0_config_bits->rx_en = 1;
}

int _entry() {

  init();

  // print hello
  uart0_puts("*****************\r\n");
  uart0_puts("* Hello, world! *\r\n");
  uart0_puts("*****************\r\n");
  uart0_puts("\r\n");

  while(1) {
    // send string through uart
    char c = uart0_getchar();
    char cmpt_str[] = "1023";
    itoa_light(c, cmpt_str);
    uart0_puts("you hit '");
    uart0_putchar(c);
    uart0_puts("' (");
    uart0_puts(cmpt_str);
    uart0_puts(")\r\n");

    // write switch state on the LED
    unsigned char switch0 = digitalRead(SWITCH_GPIO);
    digitalWrite(SWLED_GPIO, switch0);  
  }

  return 0;
}
