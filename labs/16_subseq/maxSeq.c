#include <stddef.h>
#include<stdio.h>
#include<stdlib.h>


size_t maxSeq(int * array, size_t n);

size_t maxSeq(int * array, size_t n){
    if(n==0){
        return 0;
    }
    size_t result=1;
    size_t tmplen=1;
    for(int i=1;i<n;i++){
        if(array[i]>array[i-1]){
            tmplen+=1;
        }
        else{
            if(tmplen>result){
                result=tmplen;
            }
            tmplen=1;
        }
    }
    if(tmplen>result){
        return tmplen;
    }

    return result;
}
