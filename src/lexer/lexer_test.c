#include "lexer_test.h"
#include <stdio.h>
#include <string.h>

void lexer_test_next_token(void) {
  const char *input = "let five = 5;"

                      "let ten = 10; "

                      "let add = fn(x, y) {"
                      "  x + y;"
                      "};"

                      "let result = add(five, ten);"
                      "!-/*5;"
                      "5 < 10 > 5;"

                      "if (5 < 10) {"
                      "	return true;"
                      "} else {"
                      "	return false;"
                      "}"

                      "10 == 10;"
                      "10 != 9;";

  typedef struct {
    const char *expected_type;
    const char *expected_literal;
  } TestToken;

  TestToken test_set[] = {
      {LET, "let"},      {IDENT, "five"},    {ASSIGN, "="},
      {INT, "5"},        {SEMICOLON, ";"},   {LET, "let"},
      {IDENT, "ten"},    {ASSIGN, "="},      {INT, "10"},
      {SEMICOLON, ";"},  {LET, "let"},       {IDENT, "add"},
      {ASSIGN, "="},     {FUNCTION, "fn"},   {LPAREN, "("},
      {IDENT, "x"},      {COMMA, ","},       {IDENT, "y"},
      {RPAREN, ")"},     {LBRACE, "{"},      {IDENT, "x"},
      {PLUS, "+"},       {IDENT, "y"},       {SEMICOLON, ";"},
      {RBRACE, "}"},     {SEMICOLON, ";"},   {LET, "let"},
      {IDENT, "result"}, {ASSIGN, "="},      {IDENT, "add"},
      {LPAREN, "("},     {IDENT, "five"},    {COMMA, ","},
      {IDENT, "ten"},    {RPAREN, ")"},      {SEMICOLON, ";"},
      {BANG, "!"},       {MINUS, "-"},       {SLASH, "/"},
      {ASTERISK, "*"},   {INT, "5"},         {SEMICOLON, ";"},
      {INT, "5"},        {LT, "<"},          {INT, "10"},
      {GT, ">"},         {INT, "5"},         {SEMICOLON, ";"},
      {IF, "if"},        {LPAREN, "("},      {INT, "5"},
      {LT, "<"},         {INT, "10"},        {RPAREN, ")"},
      {LBRACE, "{"},     {RETURN, "return"}, {TRUE, "true"},
      {SEMICOLON, ";"},  {RBRACE, "}"},      {ELSE, "else"},
      {LBRACE, "{"},     {RETURN, "return"}, {FALSE, "false"},
      {SEMICOLON, ";"},  {RBRACE, "}"},      {INT, "10"},
      {EQ, "=="},        {INT, "10"},        {SEMICOLON, ";"},
      {INT, "10"},       {NOT_EQ, "!="},     {INT, "9"},
      {SEMICOLON, ";"},  {ENDOFFILE, ""}};

  int test_set_len = sizeof(test_set) / sizeof(TestToken);

  Lexer l;
  lexer_init(&l, input);

  for (int i = 0; i < test_set_len; i++) {
    Token token = {"", ""};

    lexer_next_token(&token, &l);

    const char *cur_type = token.type;
    const char *expected_type = test_set[i].expected_type;
    const char *cur_literal = token.literal;
    const char *expected_literal = test_set[i].expected_literal;

    if (strcmp(cur_type, expected_type) != 0) {
      printf("lexer_tests[%d]: incorrect token type.    expected=%s, got=%s\n",
             i, expected_type, cur_type);
    }

    if (strcmp(cur_literal, expected_literal) != 0) {
      printf("lexer_tests[%d]: incorrect token literal. expected=%s, got=%s\n",
             i, expected_literal, cur_literal);
    }
  }
}
