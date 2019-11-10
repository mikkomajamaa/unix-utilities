#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // not enough input arguments
  if (argc < 2) {
    printf("my-zip: file1 [file2 ...]\n");
    exit(1);
  }
  
  FILE *fp;
  int i, c, p, counter;

  // p is the character to be counted
  p = 0;
  // counter is amount of characters
  counter = 1;

  for (i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");

    // failed to open file
    if (fp == NULL) {
      printf("my-zip: cannot open file\n");
      exit(1);
    }

    while ((c = getc(fp)) != EOF) {
      // if p == 0, c is the first character of file, so just set p = c
      if (p != 0) {
        if (p == c) { // increase counter is character to be counted (p) is the same as character read (c)
          counter += 1;
        } else { // write counter as 4 byte integer in binary format to stdout, followed by the character to be counted
          fwrite(&counter, 4, 1, stdout);
          printf("%c", p);
          counter = 1;
        }
      }

      // set p = c, so the next character to be read (c on next iteration) can be compared to previous one (p)
      p = c;
    }

    fclose(fp);
  }

  return 0;
}
