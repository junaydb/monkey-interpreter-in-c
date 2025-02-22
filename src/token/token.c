#include "token.h"

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

void token_init(Token *dest, const char *token_type, const char *byte) {
  dest->type = token_type;
  dest->literal = byte;
}
