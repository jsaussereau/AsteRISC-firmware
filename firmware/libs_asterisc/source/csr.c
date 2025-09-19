/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 *
 * csr.c
 */

#include "../include/csr.h" 

inline int csr_read(int csr) __attribute__((always_inline)) {
  int out;
  asm("csrr %0, %1" : "=r"(out) : "I"(csr_num));
  return out; 
}