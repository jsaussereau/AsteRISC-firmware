/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 * 
 * cli.h
 */

#ifndef _CLI_H_
#define _CLI_H_ 

#include "implem.h" 
#include "config.h" 
#include "commands.h" 
#include <string.h>
#include <uart.h>

void cli_execute();

#endif // _CLI_H_