#include "lexer.h"
#include "../token/token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This determines what characters are allowed in identifiers.
 * */
int is_valid_char(const char ch) {
  return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

int is_digit(const char ch) {
  return '0' <= ch && ch <= '9';
}

void read_identifier(char **dest, Lexer *l) {
  int start_position = l->position;

  while (is_valid_char(l->ch)) {
    lexer_read_char(l);
  }

  /*
   * Slice the identifier (or keyword) from the input and make `*dest` point to
   * it.
   * */
  // malloc the length of the identifier (+1 for the null terminator) and point
  // dest to this memory. Then, copy the identifier to that region of memory.
  int size = l->position - start_position;
  *dest = malloc(size + 1);
  if (*dest == NULL) {
    printf("malloc() error from `read_identifier` in `lexer.c`");
    exit(1);
  }
  memcpy(*dest, l->input + start_position, size);
  (*dest)[size] = '\0'; // null terminator
}

void read_number(char **dest, Lexer *l) {
  int start_position = l->position;

  while (is_digit(l->ch)) {
    lexer_read_char(l);
  }

  int size = l->position - start_position;
  *dest = malloc(size + 1);
  if (*dest == NULL) {
    printf("malloc() error from `read_identifier` in `lexer.c`");
    exit(1);
  }
  memcpy(*dest, l->input + start_position, size);
  (*dest)[size] = '\0'; // null terminator
}

void skip_whitespace(Lexer *l) {
  while (l->ch == ' ' || l->ch == '\t' || l->ch == '\n' || l->ch == '\r') {
    lexer_read_char(l);
  }
}

/*
 * Advances the lexer to the next character.
 */
void lexer_read_char(Lexer *l) {
  /*
   * Check if we've reached the end of the input.
   * If we have, set `ch` to 0 which is the ASCII code for the NUL char.
   * This will signify that we either haven't read anything yet or EOF.
   */
  if (l->read_position >= l->input_len) {
    l->ch = 0;
  } else {
    l->ch = l->input[l->read_position];
  }
  // `position` stores where we currently are in the input.
  // `read_position` stores the next position.
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
  skip_whitespace(l);

  switch (l->ch) {
  case '=':
    token_init(dest, ASSIGN, l->ch);
    break;
  case ';':
    token_init(dest, SEMICOLON, l->ch);
    break;
  case '(':
    token_init(dest, LPAREN, l->ch);
    break;
  case ')':
    token_init(dest, RPAREN, l->ch);
    break;
  case ',':
    token_init(dest, COMMA, l->ch);
    break;
  case '+':
    token_init(dest, PLUS, l->ch);
    break;
  case '{':
    token_init(dest, LBRACE, l->ch);
    break;
  case '}':
    token_init(dest, RBRACE, l->ch);
    break;
  case '0':
    token_init(dest, ENDOFFILE, ' ');
    break;
  /*
   * In the default case, the token can either be a keyword or illegal.
   * */
  default:
    // If the current char is a letter, then this token is either a keyword or
    // identifier, otherwise, it's an illegal token.
    if (is_valid_char(l->ch)) {
      read_identifier(&dest->literal, l);
      token_set_type_from_ident(dest);

      // Return early here because so that lexer_read_char() isn't called.
      // read_identifier() advances past the last char of the current
      // identifier, so not returning here would cause us to skip the next char.
      return;
    } else if (is_digit(l->ch)) {
      dest->type = INT;
      read_number(&dest->literal, l);
      return;
    } else {
      token_init(dest, ILLEGAL, l->ch);
    }
  }

  lexer_read_char(l);
}
