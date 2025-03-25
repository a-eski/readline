#pragma once

#include "ncsh_autocompletions.h"
#include "ncsh_arena.h"
#include "readline.h"

struct ncsh_Readline_Input {
  const char* prompt;
  Arena scratch_arena;
  Autocompletion_Node tree;
};

/* I don't use typedefs in most of my projects, but use here to keep consistent with readline style */
typedef struct ncsh_Readline_Input readline_input;

char *
ncsh_readline (readline_input *input);
