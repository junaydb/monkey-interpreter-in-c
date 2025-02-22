#include "../token/token.h"
#include <stddef.h>

#ifndef LEXER_H
#define LEXER_H

typedef struct Lexer {
  const char *input;
  size_t input_len;
  unsigned int position;
  unsigned int read_position;
  char ch;
} Lexer;

void lexer_read_char(Lexer *l);
void lexer_init(Lexer *l, const char *input);
void lexer_next_token(Token *dest, Lexer *l);

#endif
