#include <string.h>
#include <stdio.h>


int main(void) {

  int counter = 0;
  volatile int value1, value2, value3;

  printf("Long test Start\n");
  
 value1 = 5;
 value2 = 7; 
  
  while(1) {
    

    value3 += value1 * value2;

  }
  printf("OK!\n");	



  asm volatile ("ecall");

  return 0;
}
