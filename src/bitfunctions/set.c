#include "bitmask.h"
int set(int x, int y) { 
    return (x | (1 << (y - 1))); 
} 
  

