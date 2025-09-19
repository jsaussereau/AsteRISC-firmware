/*
 * Copyright(C) 2021 by Jeremie Crenne. All rights reserved.
 *
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jeremie Crenne. This copyright must be retained at all times.
 *
 * riscv.ld
 */

OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv", "elf32-littleriscv")
OUTPUT_ARCH(riscv)
ENTRY(_start)

SEARCH_DIR("=/opt/riscv/riscv32-unknown-elf/lib");
SEARCH_DIR("=/opt/riscv/riscv32-unknown-elf/lib32/ilp32d");
SEARCH_DIR("=/opt/riscv/riscv32-unknown-linux-gnu/lib32");
SEARCH_DIR("=/opt/riscv/lib");
SEARCH_DIR("=/opt/riscv/lib/gcc/riscv32-unknown-elf/11.1.0/");
SEARCH_DIR("=/opt/riscv/riscv32-unknown-linux-gnu/lib");
SEARCH_DIR("=/usr/local/lib32/ilp32d");
SEARCH_DIR("=/usr/local/lib32");
SEARCH_DIR("=/usr/local/lib"); 
SEARCH_DIR("=/lib32/ilp32d");
SEARCH_DIR("=/lib");
SEARCH_DIR("=/lib32");
SEARCH_DIR("=/usr/lib32/ilp32d");
SEARCH_DIR("=/usr/local/lib");
SEARCH_DIR("=/usr/lib");
SEARCH_DIR("=/usr/lib32");

SECTIONS
{
  .text           :
  {
    *(.text.unlikely .text.*_unlikely .text.unlikely.*)
    *(.text.exit .text.exit.*)
    *(.text.startup .text.startup.*)
    *(.text.hot .text.hot.*)
    *(.text .stub .text.* .gnu.linkonce.t.*)

    /* .gnu.warning sections are handled specially by elf32.em.  */
    *(.gnu.warning)
  }
  .data           :
  {
    __DATA_BEGIN__ = .;
    *(.data .data.* .gnu.linkonce.d.*)
    SORT(CONSTRUCTORS)
    *(.srodata.cst16) *(.srodata.cst8) *(.srodata.cst4) *(.srodata.cst2) *(.srodata .srodata.*)
    *(.sdata .sdata.* .gnu.linkonce.s.*)
    *(.sdata2 .sdata2.* .gnu.linkonce.s2.*)
    /* Put .rodata in .text */
    *(.rodata .rodata.* .gnu.linkonce.r.*) 
    *(.rodata1)
  }
  /*/DISCARD/ : { *(.comment) *(.riscv.attributes) }*/
}
