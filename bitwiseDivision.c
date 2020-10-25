#include <stdio.h>
#include <stdlib.h>

void printBinary(unsigned short n) {
  unsigned short mask = 0x8000;
  while(mask) {
    if(n & mask) {
      printf("1");
    } else {
      printf("0");
    }
    mask >>= 1;
  }
printf("\n");
}

void bitwiseDivide(unsigned short dividend, unsigned char divisor) {
  printf("Attempting to execute %d/%d\tbinary:\n", dividend, divisor);
  printBinary(dividend);
  printBinary(divisor);

  size_t size = sizeof(dividend)*8; // 16 bit quotient
  unsigned short quotient = 0x0, check_val = 0x0;
  for(size_t i = 0; i < size; i++){ //calculates the quotient
    check_val = (check_val << 1) | (0x01 & (dividend >> (size - i -1)));
    if(divisor <= check_val) {
      quotient = quotient | (0x8000 >> i); // update quotient
      check_val = check_val - divisor; // get the difference
    } // else add zeros to to quotient
    
  }
  size = 8; // 8 bit remainder
  unsigned char remainder = 0x0;
  for(size_t i = 0; i < size; i++) {
    check_val = check_val << 1;
    if(divisor <= check_val) {
      remainder = remainder | (0x80 >> i); // update quotient
      check_val = check_val - divisor; // get the difference
    }
    
  }
  printf("result: %d\nremainder: 0x%x", quotient, remainder);

}

int main(int argc, char *argv[]) {
  unsigned short dividend = 21; char divisor = 4;
  if(argc > 2) {
    dividend = atoi(argv[1]); divisor = atoi(argv[2]);
  } 
  bitwiseDivide((unsigned short)dividend, (unsigned char)divisor);
  return 0;
}
