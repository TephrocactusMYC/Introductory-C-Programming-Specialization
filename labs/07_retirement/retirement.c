#include <stdio.h>
#include <stdlib.h>
struct _retire_info
{
    int months;
    double contribution;
    double rate_of_return;
};
typedef struct _retire_info retire_info;
double compute(double balance,double rate,double contributions){
    double x;
    x=balance*(rate+1)+contributions;
    return x;
}

void retirement(int startAge,double initial,retire_info working,retire_info retired){
    double result=initial;
    printf("Age %3d month %2d you have $%.2lf\n",startAge/12,startAge%12,initial);
    for(int i=1;i<=working.months;i++){
        result=compute(result,working.rate_of_return,working.contribution);
        printf("Age %3d month %2d you have $%.2lf\n",(startAge+i)/12,(startAge+i)%12,result);
    }
    for(int j=1;j<retired.months;j++){
        result=compute(result,retired.rate_of_return,retired.contribution);
        printf("Age %3d month %2d you have $%.2lf\n",(startAge+working.months+j)/12,(startAge+working.months+j)%12,result);
    }
}
int main(void){
    retire_info Working;
    retire_info Retired;
    Working.months=489;
    Working.contribution=1000;
    Working.rate_of_return=0.045/12;
    Retired.months=384;
    Retired.contribution=-4000;
    Retired.rate_of_return=0.01/12;
    int startAge=327;
    double initial=21345;
    retirement(startAge , initial, Working, Retired);
    return 0;
}
