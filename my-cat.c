#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int i, c;

  for (i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");

    // failed to open file
    if (fp == NULL) {
      printf("my-cat: cannot open file\n");
      exit(1);
    }

    // read and print file's content
    while ((c = getc(fp)) != EOF) {
      putchar(c);
    }

    fclose(fp);
  }

  return 0;
}
