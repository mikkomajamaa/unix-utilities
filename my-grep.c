#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // not enough input arguments
  if (argc < 2) {
    printf("my-grep: searchterm [file ...]\n");
    exit(1);
  }

  int i, j;
  FILE *fp;
  char *line = NULL;
  size_t n = 0;
  char *buff = malloc(strlen(argv[1])*sizeof(char) + 1);

  // TODO: no file give, read from stdin
  if (argc == 2) {

  }

  for (i = 2; i < argc; i++) {
    fp = fopen(argv[i], "r");

    if (fp == NULL) {
      printf("my-grep: cannot open file\n");
      free(line);
      exit(1);
    }

    while (getline(&line, &n, fp) != -1) {
      // line is shorter than the search term
      if (strlen(line) - 1 < strlen(argv[1])) {
        continue;
      }

      for (j = 0; j < strlen(line) - strlen(argv[1]); j++) {
        memcpy(buff, &line[j], strlen(argv[1]));
        buff[strlen(argv[1])] = '\0';
        if (strcmp(argv[1], buff) == 0) {
          printf("%s", line);
          break;
        }
      }
    }
  }

  free(line);

  return 0;
}
