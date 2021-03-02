#include<"bitmask.h>
int flip(int x, int y){ 
    return (x ^ (1 << (y - 1))); 
}