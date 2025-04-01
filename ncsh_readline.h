/* ncsh_readline.h -- wrapper for GNU readline to enable autocompletions */

/* Copyright (C) ncsh by Alex Eski 2025 */

/* This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#pragma once
#ifndef NCSH_READLINE_H_
#define NCSH_READLINE_H_

#include "readline.h"
#include "ncsh_autocompletions.h"
#include "ncsh_arena.h"

struct ncsh_Readline_Input {
  const char* prompt;
  Arena scratch_arena;
  Autocompletion_Node* tree;
};

/* Typedef to keep consistent with readline style */
typedef struct ncsh_Readline_Input readline_input;

char *
ncsh_readline (readline_input *input);

#endif /* !NCSH_READLINE_H_ */
