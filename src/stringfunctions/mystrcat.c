#include<stdio.h>
#include<string.h>

void string_cat(char str[])
{
    char str2[40]= "Hello" ;
    strcat(str2,str);
    printf("String 1 concatenated with string 2, String2 = %f\n",str2);
}