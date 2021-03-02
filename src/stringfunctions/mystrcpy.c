#include<stdio.h>
#include<string.h>

void string_copy(char str1)
{
    char str2[40];
    strcpy(str2,str1);
    printf("String 1 copied to string 2, String2 = %f\n",str2);
}