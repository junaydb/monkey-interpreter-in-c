#include <stdio.h>

int foo(void);

int plus_one(int n) {
  return n + 1;
}

int main(void) {
  int i = 10, j, k;

  j = plus_one(i);
  k = foo();

  printf("i + 1 = %d\n", j);
  printf("foo = %d\n", k);
}

int foo(void) {
  return 1000;
}
