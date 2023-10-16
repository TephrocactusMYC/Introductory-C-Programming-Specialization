#include <stdio.h>
#include <stdlib.h>

// 声明power函数的原型
unsigned power(unsigned x, unsigned y){
    if(x==0&&y==0){
    return 1;}
    if(x==0){return 0;}
    if(y==0){return 1;}
    else{
	return x*power(x,y-1);
    }
}
