#include<stdio.h>

int vsum(int num1,...) {
   va_list valist;
     int sum = 0;
     int i;
 
     va_start(valist, num1);
     for (i = 0; i < num1; i++)
     {
         sum += va_arg(valist, int);
     }
     va_end(valist);
     return sum;
}