#include <stdio.h>

int main(void) {
  FILE* fp;
  int c = 0;

  fp = fopen("resources/hello.txt", "r");  // Open file for reading
  // Read one character at a time with fgetc() until EOF is found
  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }
  fclose(fp);  // Close the file stream

  fp = fopen("resources/quote.txt", "r");
  char s[1024];
  int linecount = 0;
  // Read one line at a time with fgets()
  while (fgets(s, sizeof(s), fp) != NULL) {
    printf("%d: %s", ++linecount, s);
  }
  fclose(fp);

  char name[1024];
  float length;
  int mass;
  fp = fopen("resources/whales.txt", "r");
  while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF) {
    printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);
  }
  fclose(fp);

  fp = fopen("resources/output.txt", "w");
  // fp = stdout;  // stdout is a file!
  int x = 32;
  // Writing to a file in various ways
  fputc('B', fp);  // Write a char
  fputc('\n', fp);
  fprintf(fp, "x = %d\n", x);    // Formatted write
  fputs("Hello, world!\n", fp);  // Write a
  fclose(fp);

  // Writing raw bytes to disk
  unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};
  fp = fopen("resources/output.bin", "wb");  // "wb" for "write binary"
  fwrite(bytes, sizeof(char), 6,
         fp);  // Write 6 elements of size char (so, 6 bytes in this case)
  fclose(fp);

  // Reading raw bytes from disk
  unsigned char b;
  fp = fopen("resources/output.bin", "rb");  // "rb" for "read binary"
  while (fread(&b, sizeof(char), 1, fp) > 0) {
    printf("%d\n", b);
  }
  fclose(fp);

  // Endianess and structs
  unsigned short v = 0x1234;
  fp = fopen("resources/endianess.bin", "wb");
  fwrite(&v, sizeof(v), 1, fp);
  fclose(fp);
}
