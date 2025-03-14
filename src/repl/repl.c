#include "repl.h"
#include "../lexer/lexer.h"
#include "../token/token.h"
#include <stdio.h>
#include <string.h>

void repl(void) {
  while (1) {
    char buffer[1024];

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      buffer[strcspn(buffer, "\n")] = '\0';

      if (buffer[0] == '\0') {
        return;
      }

      Token token;
      Lexer l = lexer_init(buffer);

      for (lexer_next_token(&token, &l); strcmp(token.type, ENDOFFILE);
           lexer_next_token(&token, &l)) {
        printf("{Type: %s, Literal: %s}\n", token.type, token.literal);
      }
    } else {
      return;
    }
  }
}
