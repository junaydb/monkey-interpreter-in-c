#include "lexer/lexer.h"
#include <stdio.h>

int main(void) {
  const char *input = "This is a test";

  Lexer l;
  lexer_init(&l, input);
  printf("%d\n", l.input_len);

  for (int i = 0; i < l.input_len; i++) {
    printf("pos: %d, char: %c\n", l.position, l.ch);
    lexer_read_char(&l);
  }
}
