/* ncsh arena - a way to allocate memory used by ncsh */

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

#include <stdint.h>

struct ncsh_Arena {
    char* start;
    char* end;
};

/* I don't use typedefs in most of my projects, but use here to keep consistent with readline style */
typedef struct ncsh_Arena Arena;

#define arena_malloc(arena, count, type) \
    (type*)ncsh_arena_malloc_internal(arena, count, sizeof(type), _Alignof(type))

void* ncsh_arena_malloc_internal(struct ncsh_Arena* arena,
                     uintptr_t count,
                     uintptr_t size,
                     uintptr_t alignment);

#define arena_realloc(arena, count, type, ptr, old_count) \
    (type*)ncsh_arena_realloc_internal(arena, count, sizeof(type), _Alignof(type), ptr, old_count);

void* ncsh_arena_realloc_internal(struct ncsh_Arena* arena,
                     uintptr_t count,
                     uintptr_t size,
                     uintptr_t alignment,
                     void* old_ptr,
                     uintptr_t old_count);
