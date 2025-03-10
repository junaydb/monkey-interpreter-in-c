#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *ILLEGAL = "ILLEGAL";
const char *ENDOFFILE = "EOF";

// Identifiers + literals
const char *IDENT = "IDENT"; // add, foobar, x, y, ...
const char *INT = "INT";     // 1343456

// Operators
const char *ASSIGN = "=";
const char *PLUS = "+";
const char *MINUS = "-";
const char *BANG = "!";
const char *ASTERISK = "*";
const char *SLASH = "/";

const char *LT = "<";
const char *GT = ">";

const char *EQ = "==";
const char *NOT_EQ = "!=";

// Delimiters
const char *COMMA = ",";
const char *SEMICOLON = ";";

const char *LPAREN = "(";
const char *RPAREN = ")";
const char *LBRACE = "{";
const char *RBRACE = "}";

// Keywords
const char *FUNCTION = "FUNCTION";
const char *LET = "LET";
const char *TRUE = "TRUE";
const char *FALSE = "FALSE";
const char *IF = "IF";
const char *ELSE = "ELSE";
const char *RETURN = "RETURN";

void token_init(Token *dest, const char *token_type, char byte) {
  dest->type = token_type;

  // Copy the literal here as we'll lose it when the lexer moves to the next
  // token.
  dest->literal = malloc(2);
  dest->literal[0] = byte;
  dest->literal[1] = '\0';
}

/*
 * Until I can be bothered to find a good map implementation or implement a one
 * myself, this is fine.
 */
void token_set_type_from_ident(Token *dest) {
  if (dest == NULL || dest->literal == NULL) {
    return;
  }

  if (strcmp(dest->literal, "fn") == 0) {
    dest->type = FUNCTION;
  } else if (strcmp(dest->literal, "let") == 0) {
    dest->type = LET;
  } else if (strcmp(dest->literal, "true") == 0) {
    dest->type = TRUE;
  } else if (strcmp(dest->literal, "false") == 0) {
    dest->type = FALSE;
  } else if (strcmp(dest->literal, "if") == 0) {
    dest->type = IF;
  } else if (strcmp(dest->literal, "else") == 0) {
    dest->type = ELSE;
  } else if (strcmp(dest->literal, "return") == 0) {
    dest->type = RETURN;
  } else {
    dest->type = IDENT;
  }
}
