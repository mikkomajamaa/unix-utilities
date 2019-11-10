#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int i, c, p, counter;
  p = 0;
  counter = 1;

  // not enough input arguments
  if (argc < 2) {
    return 0;
  }

  for (i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");

    // failed to open file
    if (fp == NULL) {
      printf("my-zip: cannot open file\n");
      exit(1);
    }

    while ((c = getc(fp)) != EOF) {
      if (p != 0) {
        if (p == c) {
          counter += 1;
        } else {
          //putchar(p);
          //fwrite(&counter, 4, 1, stdout);
          // TODO: change to 4-byte integer in binary form
          printf("%d", counter);
          printf("%c", p);
          //printf("%d", counter);
          counter = 1;
        }
      }

      p = c;
    }

    fclose(fp);
  }

  return 0;
}
