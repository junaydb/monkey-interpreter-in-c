#include <stdio.h>

void increment(int* p) {
  printf("The address of p (in the param list) is %p\n", (void*)&p);
  (*p)++;
}

int main(void) {
  int i = 10;
  int* p;

  p = &i;

  printf("The value of i is %d\n", i);
  printf("The address of i is %p\n", (void*)&i);
  printf("The address of p is %p\n", (void*)&p);

  *p = 20;

  printf("The value of i is %d\n", i);

  increment(p);

  printf("The value of i is %d\n", i);

  increment(&i);
}
