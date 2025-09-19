/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 * 
 * commands.h
 */
 
#ifndef _COMMANDS_H_
#define _COMMANDS_H_ 

#include <string.h>
#include "implem.h" 
#include "config.h" 

#define COMMAND_COUNT 5

typedef struct {
  char name[16];
  char args[32];
  char description[128];
  void (*implementation) (char*);
} command_t;

extern command_t commands[COMMAND_COUNT];

void print_dec_hex_bin(unsigned long data);

void help(char* args);
void read_data(char* args);
void write_data(char* args);
void echo(char* args);
void cute(char* args);

#endif // _COMMANDS_H_