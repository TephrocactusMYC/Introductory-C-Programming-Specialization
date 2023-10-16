#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

char *getEqual(char * line) {
    char *key_end=strchr(line,'=');
    char *value_end=strchr(line,'\n');
    if (key_end != NULL && value_end != NULL) {
    *key_end = '\0';
    *value_end = '\0';
    }

    return key_end+1;
}
kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE *f=fopen(fname,"r");
  char *line=NULL;
  size_t sz=0;

  kvarray_t *arrays=malloc(sizeof(*arrays));
  arrays->array = NULL;
  arrays->arrlen = 0;
  size_t lines=0;
  while(getline(&line,&sz,f)>=0){
    char *temp=getEqual(line);
    if(temp) {
      kvpair_t *kvPair = malloc(sizeof(*kvPair));
      kvPair->key = malloc((strlen(line) + 1) * sizeof(kvPair->key));
      kvPair->value = malloc((strlen(temp) + 1) * sizeof(kvPair->value));
      strcpy(kvPair->key, line);
      strcpy(kvPair->value, temp);
      arrays->array=realloc(arrays->array,(lines+1)*sizeof(kvpair_t));
      arrays->array[lines] = *kvPair;
      lines+=1;
      arrays->arrlen = lines;
      free(kvPair);
    }
  }
  free(line);

  if(fclose(f)!=0){
    perror("Failed to close the input file!\n");
    return NULL;
    }
  return arrays;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->arrlen; i++) {
    free(pairs->array[i].key);
    free(pairs->array[i].value);
  }
  free(pairs->array);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->arrlen; i++) {
    printf("key = '%s' value = '%s'\n", pairs->array[i].key,pairs->array[i].value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for (int i = 0; i < pairs->arrlen; i++){
    if(!strcmp(pairs->array[i].key,key)){
        return pairs->array[i].value;
    }
  }
  return NULL;
}
