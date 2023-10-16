#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void rotate(char matrix[10][10])
{
    // 这个题目有个技巧，先对角线翻转，再左右反转即可
    // 对角线
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            char tmp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=tmp;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            char tmp=matrix[i][10-j-1];
            matrix[i][10-j-1]=matrix[i][j];
            matrix[i][j]=tmp;
        }

    }

}


int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: rotateMatrix inputFileName\n");
    return EXIT_FAILURE;
  }

  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Could not open file\n");
    return EXIT_FAILURE;
  }
  char line[12];
  char matrix[10][10];
  int lineNumber = 0;
  while (fgets(line, 12, f) != NULL) {
    if (lineNumber >= 10) {
      fprintf(stderr, "Too many lines!\n");
      return EXIT_FAILURE;
    }
    if (strchr(line, '\n') == NULL) {
      fprintf(stderr, "Line is too long!\n");
      return EXIT_FAILURE;
    }
    if ((strchr(line, '\n') - line) != 10) {
      fprintf(stderr, "Line is too short!\n");
      return EXIT_FAILURE;
    }
    for (int j = 0; j < 10; j++) {
      if (line[j] == '\n') {
        fprintf(stderr, "Line is too short!\n");
        return EXIT_FAILURE;
      }
      matrix[lineNumber][j] = line[j];
    }
    lineNumber++;
  }

  if (lineNumber != 10) {
    fprintf(stderr, "Not enough number of lines\n");
    return EXIT_FAILURE;
  }

  rotate(matrix);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
