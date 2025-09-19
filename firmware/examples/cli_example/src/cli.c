/*
 * Copyright(C) 2022 by Jonathan Saussereau. All rights reserved.
 * 
 * All source codes and documentation contain proprietary confidential
 * information and are distributed under license. It may be used, copied
 * and/or disclosed only pursuant to the terms of a valid license agreement
 * with Jonathan Saussereau. This copyright must be retained at all times.
 * 
 * cli.c
 */

#include "cli.h" 

void cli_execute() {
  char input_buffer[MAX_INPUT_CHARACTERS];
  unsigned short cursor_pos = 0;
  char c;

  my_puts(PROMPT_COLOR);
  my_puts(PROMPT_MSG);
  my_puts(_END);

  while ((c = my_getchar()) != INPUT_KEY_ENTER) {
    if (cursor_pos < MAX_INPUT_CHARACTERS - 1) {
      if (c == INPUT_KEY_BACKSPACE || c == INPUT_KEY_DELETE) {
        if (cursor_pos > 0) {
          my_putchar(c);
          cursor_pos--;
        }
      } else {
        my_putchar(c);
        input_buffer[cursor_pos] = c;
        cursor_pos++;
      }
    }
  }

  my_puts(OUTPUT_NEWLINE);

  if (cursor_pos == 0) {
    return;
  }

  input_buffer[cursor_pos] = '\0';

  char* command = my_strtok(input_buffer, COMMAND_SEPARATOR);
  char* arg = my_strtok(NULL, "");

  unsigned char command_found = 0;
  for (unsigned char i = 0 ; i < COMMAND_COUNT ; i++) {
    if (my_strcmp(command, commands[i].name) == 0) {
      (commands[i].implementation)(arg);
      command_found = 1;
      break;
    }
  }
  if (!command_found) {
    my_puts(ERROR_COLOR);
    my_puts(UNKNOWN_MSG);
    my_puts(_END);
  }
  my_puts(OUTPUT_NEWLINE);
}