#include<stdio.h>
#include<string.h>

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
