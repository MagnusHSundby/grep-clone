#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Need at least 3 argc");
    return 1;
  }

  FILE *fp = fopen(argv[2], "r");

  if (fp == NULL) {
    perror(argv[2]);
    return 1;
  }
  int counter;
  char lower_pattern[4096];
  for (counter = 0; argv[1][counter] != '\0'; counter++) {
    lower_pattern[counter] = tolower(argv[1][counter]);
  }
  lower_pattern[counter] = '\0';
  int line_count = 1;
  char line[4096];
  char lower_line[4096];
  int i;
  while (fgets(line, sizeof(line), fp)) {
    for (i = 0; line[i] != '\0'; i++) {
      lower_line[i] = tolower(line[i]);
    }
    lower_line[i] = '\0';
    if (strstr(lower_line, lower_pattern)) {
      printf("Line: %d %s", line_count, line);
    }
    line_count++;
  }
  fclose(fp);
  return 0;
}
