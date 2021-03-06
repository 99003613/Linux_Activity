#include<stdio.h>
int isPalindrome(int num1){
    int r,sum=0,temp;   
    temp=num1;    
    while(num1>0)    
    {    
    r=num1%10;    
    sum=(sum*10)+r;    
    num1=num1/10;    
    }    
    if(temp==sum)    
        return 1;    
    else   
        return 0;
}