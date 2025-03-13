#include "../token/token.h"
#include <stddef.h>

#ifndef LEXER_H
#define LEXER_H

typedef struct Lexer {
  const char *input;
  unsigned int input_len;
  unsigned int position;      // position in input (points to current char)
  unsigned int read_position; // reading position in input (after current char)
  char ch;                    // char under examination
} Lexer;

Lexer lexer_init(const char *input);
void lexer_read_char(Lexer *l);
void lexer_next_token(Token *dest, Lexer *l);

#endif
