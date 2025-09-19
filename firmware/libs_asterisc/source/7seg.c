/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 *
 * 7seg.c
 */

#include "../include/7seg.h" 

seven_segment_t get_7seg_value(unsigned char input) {
  seven_segment_t result;
  if (input == 0) {
    result.value = 0xfc; // 0b11111100
  } else if (input == 1) {
    result.value = 0x60; // 0b01100000
  } else if (input == 2) {
    result.value = 0xda; // 0b11011010
  } else if (input == 3) {
    result.value = 0xf2; // 0b11110010
  } else if (input == 4) {
    result.value = 0x66; // 0b01100110
  } else if (input == 5) {
    result.value = 0xb6; // 0b10110110
  } else if (input == 6) {
    result.value = 0xbe; // 0b10111110
  } else if (input == 7) {
    result.value = 0xe0; // 0b11100000
  } else if (input == 8) {
    result.value = 0xfe; // 0b11111110
  } else if (input == 9) {
    result.value = 0xf6; // 0b11110110
  } else if (input == 10) {
    result.value = 0xee; // 0b11101110
  } else if (input == 11) {
    result.value = 0x3e; // 0b00111110
  } else if (input == 12) {
    result.value = 0x9c; // 0b10011100
  } else if (input == 13) {
    result.value = 0x7a; // 0b01111010
  } else if (input == 14) {
    result.value = 0x9e; // 0b10011110
  } else if (input == 15) {
    result.value = 0x8e; // 0b10001110
  } else {
    result.value = 0x02; // 0b00000010;
  }
  return result;
}
