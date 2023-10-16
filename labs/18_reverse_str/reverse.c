#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  //WRITE ME!
  if(!str){
  return ;}
    int strlen=0;
    const char *tmp_ptr=str;
    while(*tmp_ptr!='\0'){
    	tmp_ptr++;
        strlen+=1;
    }
    char tmp_char;
    // 现在我们有长度了
    // printf("%d\n", strlen);
    for(int i=0;i<strlen/2;i++){
        tmp_char=str[i];
        str[i]=str[strlen-i-1];
        str[strlen-i-1]=tmp_char;
    }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
