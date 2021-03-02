#include<stdio.h>
int factorial(int num1){
    int i,factorial=1;
    if(num1<0)
        factorial=-1;
    else if(num1==0 || num1==1)
        factorial=1;
    else {
        for(i=1;i<=num1;i++){
            factorial=factorial*i;
        }
        
    }
        return factorial;
}