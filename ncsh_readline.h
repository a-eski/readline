#ifndef NCSH_READLINE_H_

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
