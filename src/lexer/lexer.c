#include "lexer.h"
#include "../token/token.h"
#include <string.h>

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
    // passing "" is fine because string literals have static storage duration
    token_init(dest, ENDOFFILE, "");
    break;
  }

  lexer_read_char(l);
}
