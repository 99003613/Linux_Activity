#include<stdio.h>
#include<string.h>

int string_copy(char str[])
{
    char str2[40];
    strcpy(str2,str);
    printf("String 1 copied to string 2, String2 = %f\n",str2);

    return 0
}