#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int i, j, k;
  // c is count of characters
  int *c = malloc(sizeof(int));

  for (i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");

    // failed to open file
    if (fp == NULL) {
      printf("my-unzip: cannot open file\n");
      exit(1);
    }

    // get count of first character
    fread(c, 4, 1, fp);

    while ((k = getc(fp)) != EOF) {
      // print as many characters as c indicates
      for (j = 0; j < *c; j++) {
        putchar(k);
      }
      // read amount of next character
      fread(c, 4, 1, fp);
    }

    fclose(fp);
  }

  return 0;
}
