#include<stdio.h>
#include<string.h>

int string_compare(char str[])
{
    char str2[40]= "Hello" ;
    
    int res = strcmp(str2, str); 
      
    if (res==0) 
        printf("Strings are equal"); 
    else 
        printf("Strings are unequal"); 

return 0
}