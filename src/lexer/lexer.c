#include "lexer.h"
#include "../token/token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This function determines what characters are allowed in identifiers
 * */
int is_valid_char(const char ch) {
  return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

void read_identifier_or_keyword(char **dest, Lexer *l) {
  unsigned int position = l->position;

  while (is_valid_char(l->ch)) {
    lexer_read_char(l);
  }

  /*
   * Slice the identifier (or keyword) from the input make `dest` point to it.
   * */
  // malloc the length of the identifier (+1 for the null terminator) and point
  // dest to this memory. Then, copy the identifier to that region of memory.
  int size = l->position - position;

  if ((*dest = malloc(size + 1)) == NULL) {
    printf("malloc() error from `read_identifier` in `lexer.c`");
  }
  memcpy(*dest, l->input + position, size);
  (*dest)[size] = '\0';
}

void lexer_read_char(Lexer *l) {
  if (l->read_position >= l->input_len) {
    l->ch = 0;
  } else {
    l->ch = l->input[l->read_position];
  }
  l->position = l->read_position;
  l->read_position += 1;
}

void lexer_init(Lexer *l, const char *input) {
  l->input = input;
  l->input_len = strlen(input);
  l->position = 0;
  l->read_position = 0;
  l->ch = 0;

  lexer_read_char(l);
}

void lexer_next_token(Token *dest, Lexer *l) {
  switch (l->ch) {
  case '=':
    token_init(dest, ASSIGN, &l->ch);
    break;
  case ';':
    token_init(dest, SEMICOLON, &l->ch);
    break;
  case '(':
    token_init(dest, LPAREN, &l->ch);
    break;
  case ')':
    token_init(dest, RPAREN, &l->ch);
    break;
  case ',':
    token_init(dest, COMMA, &l->ch);
    break;
  case '+':
    token_init(dest, PLUS, &l->ch);
    break;
  case '{':
    token_init(dest, LBRACE, &l->ch);
    break;
  case '}':
    token_init(dest, RBRACE, &l->ch);
    break;
  case '0':
    token_init(dest, ENDOFFILE, "");
    break;
  /*
   * In the default case, the token can either be a keyword or illegal.
   * */
  default:
    /*
     * If the current char is a letter, then this token is either a keyword or
     * identifier, otherwise, it's an illegal token.
     * */
    if (is_valid_char(l->ch)) {
      read_identifier_or_keyword(&dest->literal, l);
      token_set_type(dest);
      return;
    } else {
      token_init(dest, ILLEGAL, &l->ch);
    }
  }

  lexer_read_char(l);
}
