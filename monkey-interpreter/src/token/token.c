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

typedef const char *TokenType;

typedef struct {
  TokenType type;
  char *literal;
} Token;

void test_next_token(void) {
  char *input = "let five = 5;"

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
    TokenType expected_type;
    char *expected_literal;
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
  ;
}
