#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int decrypt(FILE * f){
int c;
  int letters[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      letters[c] = letters[c] + 1;
    }
  }
  int tmpindex=0;
  int maxchar=letters[0];
  for(int i=1;i<26;i++){
    if(letters[i]>maxchar){
      maxchar=letters[i];
      tmpindex=i;
    }
  }
  int result=0;
  if (tmpindex >= 4) {
    result = tmpindex - 4;
  } else {
    result = 26 - (4 - tmpindex);
  }
  return result;
}
int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: breaker inputFileName\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int result=decrypt(f);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  printf("%d\n", result);
  return EXIT_SUCCESS;
}
