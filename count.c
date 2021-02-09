#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Missing file\n");
    printf("Usage: ./count file.txt\n");
    return 0;
  }

  int totalChars = 0;
  int totalLines = 0;
  int totalWords = 0;
  int spaceSpot = 1;
  int curr, last = '\n';

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
	   printf("Error opening file!");
	   return 0;
  }

  while ((curr = fgetc(fp)) != EOF) {
      last = curr;
      totalChars++;
      if (isspace(curr)) {
           spaceSpot = 1;
	         if (curr == '\n') {
	            totalLines++;
	         }
      }
      else {
         totalWords += spaceSpot;
	       spaceSpot = 0;
      }
  }
  if (last != '\n') {
      totalLines++;
  }
  fclose(fp);
  printf("Lines, Words, Characters\n");
  printf(" %3d %3d %3d\n", totalLines, totalWords, totalChars);

  return 0;
}
