#include <stdio.h>
#include <string.h>

int my_strlen(char* s) {
  int count = 0;
  while (s[count] != '\0') count++;
  return count;
}

int main(void) {
  // A string is actually a pointer to the first character in that string. 
  char *s = "Hello, world.";
  printf("%s\n", s);

  // To prove it:
  char s2[] = "(I'm secretly an array)"; // The compiler automatically calculates the length for us here.
  printf("%s\n", s2);

  // But there is an IMPORTANT difference between these two declarations:
  //
  // Strings declared like this cannot be mutated:
  char *imm = "I'm immutable.\n";
  // imm[0] = 'z'; // Throws (Address Boundary Error)
  //
  // But strings declared like this can be:
  char mut[] = "I'm mutable\n";
  mut[0] = 'z';
  printf("%s", mut);

  // strlen (from string.h) can be used to compute a string's length in byes.
  printf("The string '%s' is %zu bytes (1 byte per char, so 15 chars)\n", s, strlen(imm));

  // Strings are terminated by a NUL character: \0
  char *t = "Hello"; // Actually "Hello\0" behind the scenes.
  printf("%d\n", my_strlen(t));

  // Copying strings:
  //
  // Doing the following doesn't copy the string, it just copies the pointer to the first character:
  char original[] = "Original";
  char* copy = original;
  copy[0] = 'z';
  printf("%s\n", original); // The original string has been mutated
  //
  // strcpy is used for copying
  char new_original[] = "Original";
  char real_copy[strlen(new_original)];
  strcpy(real_copy, new_original);
  real_copy[0] = 'z';
  printf("%s\n", new_original); // The original string hasn't changed
}
