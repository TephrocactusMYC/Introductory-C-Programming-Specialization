#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * count = malloc(sizeof(*count));
  count -> arr = NULL;
  count -> arraySize = 0;
  count -> arr = malloc (sizeof(one_count_t *));
  count -> count_of_unknowns = 0;
  return count;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
    if (name == NULL) {
        ++ c -> count_of_unknowns;
        return ;
    }
    for (int i = 0; i < c -> arraySize; i ++) {
        if (!strcmp(c -> arr[i] -> value, name)) {
            ++ c -> arr[i] -> count;
            return;
        }
    }
    c -> arr = realloc(c -> arr, ((c -> arraySize) + 1) * sizeof (one_count_t *));
    c -> arr[c -> arraySize] = NULL;

    c -> arr[c -> arraySize] = malloc(sizeof(one_count_t));
    c -> arr[c -> arraySize] -> value = NULL;
    c -> arr[c -> arraySize] -> value = malloc(strlen(name) + 1);
    strcpy(c -> arr[c -> arraySize] -> value, name);
    c -> arr[c -> arraySize] -> count  = 1;
    ++ c -> arraySize;
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for (int i = 0; i < c -> arraySize; i ++) {
        fprintf(outFile, "%s: %d\n", c -> arr[i] -> value, c -> arr[i] -> count);
    }

    if (c -> count_of_unknowns)
        fprintf(outFile, "<unknown> : %d\n", c -> count_of_unknowns);
}

void freeCounts(counts_t * c) {
  //WRITE ME
    for (int i = 0; i < c -> arraySize; i ++) {
        free(c -> arr[i] -> value);
        free(c -> arr[i]);
    }
    // be clearly that which pointer be allocated the memory
    free(c -> arr);
    free(c);
}

