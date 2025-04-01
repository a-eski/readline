/* autocompletions.c -- autocompletions for readline */

/* Copyright (C) ncsh by Alex Eski 2024 */

/* Based on eskilib_trie prefix tree implementation */

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

#ifndef NCSH_AUTOCOMPLETIONS_H_

// #if defined (READLINE_LIBRARY)
#  include "ncsh_arena.h"
#  include "ncsh_string.h"
// #else
// #  include <readline/ncsh_arena.h>
// #  include <readline/ncsh_string.h>
// #endif

/* NCSH_MAX_AUTOCOMPLETION_MATCHES Macro constant
 * Max number of matches a single autocompletion request can return. Used in tab autocomplete use case.
 */
#ifndef NCSH_MAX_AUTOCOMPLETION_MATCHES
#   define NCSH_MAX_AUTOCOMPLETION_MATCHES 32
#endif // !NCSH_MAX_AUTOCOMPLETION_MATCHES

#ifndef NCSH_LETTERS
#   define NCSH_LETTERS 96 // ascii printable characters 32-127
#endif // !NCSH_LETTERS

// Forward Declaration: prefix tree for storing autocomplete posibilities
struct ncsh_Autocompletion_Node;

// Type Declaration: prefix tree for storing autocomplete possibilities
struct ncsh_Autocompletion_Node {
    bool is_end_of_a_word;
    uint_fast8_t weight;
    struct ncsh_Autocompletion_Node* nodes[NCSH_LETTERS];
};

/* Typedef to keep consistent with readline style */
typedef struct ncsh_Autocompletion_Node Autocompletion_Node;

struct ncsh_Autocompletion {
    uint_fast8_t weight;
    char* value;
};

/* I don't use typedefs in most of my projects, but use here to keep consistent with readline style */
typedef struct ncsh_Autocompletion Autocompletion;

inline int ncsh_char_to_index(const char character)
{
    return (int)character - ' ';
}
inline char ncsh_index_to_char(const int index)
{
    return (char)index + ' ';
}

struct ncsh_Autocompletion_Node* ncsh_autocompletions_alloc(struct ncsh_Arena* const arena);

void ncsh_autocompletions_add(const char* const string,
                              const size_t length,
                              struct ncsh_Autocompletion_Node* tree,
                              struct ncsh_Arena* const arena);

void ncsh_autocompletions_add_multiple(struct ncsh_String* const strings,
                                       const int count,
                                       struct ncsh_Autocompletion_Node* tree,
                                       struct ncsh_Arena* const arena);

struct ncsh_Autocompletion_Node* ncsh_autocompletions_search(const char* const string,
                                                             const size_t length,
                                                             struct ncsh_Autocompletion_Node* tree);

struct ncsh_Autocompletion_Node* ncsh_autocompletions_search_string(const struct ncsh_String string,
                                                                    struct ncsh_Autocompletion_Node* tree);

// gets all matches based on traversing the tree.
// populates matches into variable matches and returns 0 if no matches, number of matches length if any matches.
uint_fast8_t ncsh_autocompletions_get(const char* const search,
                                      const size_t search_length,
                                      struct ncsh_Autocompletion* matches,
                                      struct ncsh_Autocompletion_Node* tree,
                                      struct ncsh_Arena scratch_arena);

// gets highest weighted match based on traversing the tree.
// populates match into variable match and returns 0 if not matches, 1 if any matches.
uint_fast8_t ncsh_autocompletions_first(const char* const search,
                                        const size_t search_length,
                                        char* match,
                                        struct ncsh_Autocompletion_Node* tree,
                                        struct ncsh_Arena scratch_arena);

#endif /* !NCSH_AUTOCOMPLETIONS_H_ */
