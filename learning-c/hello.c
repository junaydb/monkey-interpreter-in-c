#include <stdio.h>

int main(void) {
  int i = 2;
  float f = 3.14;
  char* s = "Hello, world!";

  printf("%s i = %d and f = %f!\n", s, i, f);

  for (int i = 0, j = 100; i < 100; i++, j++) {
    printf("%d, %d\n", i, j);
  }

  printf("size of int: %zu bytes\n", sizeof(int));
  printf("size of char: %zu bytes\n", sizeof(char));
}
