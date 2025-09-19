/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 *
 * spi_slave.c
 */

#include "../include/spi_slave.h"

uint8_t spi_get_byte() {
  //while(spi_status_rx_bits->fifo_empty); //wait for a byte
  while(*spi_status_rx_fifo_empty); //wait for a byte
  return *spi_data_rx;
}