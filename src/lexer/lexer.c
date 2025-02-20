#include "lexer.h"
#include "../token/token.h"
#include <string.h>

void lexer_init(Lexer *l, const char *input) {
  l->input = input;
  l->input_len = strlen(input);
  l->position = 0;
  l->read_position = 0;
  l->ch = 0;

  lexer_read_char(l);
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

const char *lexer_next_token(Token *dest, Lexer *l) {
  switch (l->ch) {
  case '=':
    *dest = token_init(ASSIGN, l.ch);
    break;
  case ';':
    *dest = token_init(SEMICOLON, l.ch);
    break;
  case '(':
    *dest = token_init(LPAREN, l.ch);
    break;
  case ')':
    *dest = token_init(RPAREN, l.ch);
    break;
  case ',':
    *dest = token_init(COMMA, l.ch);
    break;
  case '+':
    *dest = token_init(PLUS, l.ch);
    break;
  case '{':
    *dest = token_init(LBRACE, l.ch);
    break;
  case '}':
    *dest = token_init(RBRACE, l.ch);
    break;
  case '0':
    *dest = token_init(ENDOFFILE, "");
    break;
  }

  lexer_read_char(&l);
}
