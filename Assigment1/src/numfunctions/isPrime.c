#include<stdio.h>
int isPrime(int num1){
    int count=0,i, result=0;
    if(num1<=0)
        result= -1;
    else{
        for(i=1;i<=num1;i++){
            if(num1%i==0)
                count++;
        }
        if(count==2)
            result= 1;
        else
            result= 0;
    }
    return result;

}