#
# Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
# Copyright(C) 2021 by Jeremie Crenne. All rights reserved.
#
# All source codes and documentation contain proprietary confidential
# information and are distributed under license. It may be used, copied
# and/or disclosed only pursuant to the terms of a valid license agreement
# with Jeremie Crenne. This copyright must be retained at all times.
#
# start_rv32e.S
#

.text
.align 2
.globl _start
.type  _start, @function
.org   0

_start:
  addi x1, zero, 0
  addi x2, zero, 0
  addi x3, zero, 0
  addi x4, zero, 0
  addi x5, zero, 0
  addi x6, zero, 0
  addi x7, zero, 0
  addi x8, zero, 0
  addi x9, zero, 0
  addi x10, zero, 0
  addi x11, zero, 0
  addi x12, zero, 0
  addi x13, zero, 0
  addi x14, zero, 0
  addi x15, zero, 0
  lui  a1, 0x10001
  addi sp, a1, -4
  jal  ra, _entry
  j    _start 
