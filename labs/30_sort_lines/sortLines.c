#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}
void helper(FILE * f){
  char **lines=NULL;
  size_t sz=0;
  char * curr=NULL;
  size_t index=0;
  while(getline(&curr,&sz,f)>=0){
    lines=realloc(lines,(index+1)*sizeof(*lines));
    lines[index]=curr;
    curr=NULL;
    index++;
  }
  free(curr);
  sortData(lines,index);
  for(size_t i=0;i<index;i++){
    printf("%s",lines[i]);
    free(lines[i]);
  }
  free(lines);
}
int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  if(argc==1){
    helper(stdin);
  } 
  else{
    for(size_t i=1;i<argc;i++){
      FILE *f=fopen(argv[i],"r");
      if(f==NULL){
        fprintf(stderr,"Error happens!\n");
	return EXIT_FAILURE;
      }
      helper(f);
      if(fclose(f)!=0){
        fprintf(stderr,"Closing File Failed!\n");
	return EXIT_FAILURE;
      }
    }
  }
  return EXIT_SUCCESS;
}
