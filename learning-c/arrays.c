#include <stdio.h>

void times2(int* arr, int len) {
  printf("Length: %d\n", len);
  for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i] * 2);
  }
}

int main(void) {
  float f[4];

  f[0] = 3.14159;
  f[1] = 1.41421;
  f[2] = 1.61803;
  f[3] = 3.71828;

  for (int i = 0; i < 4; i++) {
    printf("index %d is: %f\n", i, f[i]);
  }

  int x[12];

  printf("total size of array: %zu\n", sizeof(x));
  printf("size of int: %zu\n", sizeof(int));
  printf("length of array: %zu\n", sizeof(x) / sizeof(int));

  // Getting the sie of an array without declaring an array
  printf("size of array with 12 doubles: %zu\n", sizeof(double[12]));

  // Array initialisation with constants
  int a[5] = {22, 37, 40};  // last 2 elements are set to 0 automatically
  int b[] = {22, 37, 40};   // size is automatically computed here

  int c[100] = {0};  // fill array with zeros

  // This MAY work even though we're accessing index past the bounds of the
  // array. This is UNDEFINED behaviour in C and no warning is given. SCARY! for
  // (int i = 0; i < 10; i++) {
  //   printf("%d\n", a[i]);
  // }

  int md[2][5];        // 2d array
  int img[10][10][3];  // 3d array
  printf("%zu\n", sizeof(img));

  int y[5] = {1, 2, 3, 4, 5};
  int* yp;

  yp = &y[0];  // Points to the first element of the array,
               // effectively the same as pointing to the array.

  printf("%d\n", *yp);

  yp = y;  // Effectively the same thing as above, but nicer

  printf("%d\n", *yp);

  times2(yp, sizeof(y) / sizeof(int));
}
