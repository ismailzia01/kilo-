#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
  if (argc != 3 || strcmp(argv[1], "-c") != 0) {
    fprintf(stderr, "usage : ccwc -c file\n");
    return 1;
  }
  const char *filename = argv[2];

  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror(filename);
    return 1;
  }
  long bytes = 0;
  int c;
  while ((c = fgetc(fp)) != EOF)
    bytes++;
  printf("%8ld %s\n", bytes, filename);
  fclose(fp);

  return 0;
}