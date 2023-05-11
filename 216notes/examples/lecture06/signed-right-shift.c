#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates a signed right shift on Grace; results may differ on
   different machines or compilers */

static void print_binary(unsigned int n);

/* just like the iterative version in the lecture slides- which has a bug-
   this recursive print_binary() function does not correctly handle the case
   where n is 0 (it just doesn't print anything in that case)- exercise for
   the reader is to fix this so it just prints 0 if n is 0 */
void print_binary(unsigned int n) {
  if (n != 0) {
    print_binary(n >> 1);

    if ((n & 1) == 0)
      printf("0");
    else printf("1");
  }
}

/* before running the program, good practice would be to figure out manually
   what y and z are in binary yourself (note z is 32 bits and is stored
   using twos complement */

int main(void) {
  unsigned int x= 2147483864;  /* this is obviously an unsigned type */
  int y= 216, z= -216;  /* these are signed types */

  printf("x = %10u, which in binary is ", x);
  print_binary(x);
  printf("\ny = %10d, which in binary is ", y);
  print_binary(y);
  printf("\nz = %10d, which in binary is ", z);
  print_binary(z);
  printf("\n");

  /* right shift all three of them by 1 bit */
  x >>= 1;
  y >>= 1;
  z >>= 1;

  /* we can see that right shifting an unsigned integer type zero fills
   * (always, according to the language standard), while on Grace, right
   * shifting y and z, which are signed integer types, fills the leftmost
   * bits with the replicated sign bit (the leftmost bit)
   */
  printf("\nx = %10u, which in binary is ", x);
  print_binary(x);
  printf("\ny = %10d, which in binary is ", y);
  print_binary(y);
  printf("\nz = %10d, which in binary is ", z);
  print_binary(z);
  printf("\n");

  /* right shift all three of them by 2 bits */
  x >>= 2;
  y >>= 2;
  z >>= 2;

  printf("\nx = %10u, which in binary is ", x);
  print_binary(x);
  printf("\ny = %10d, which in binary is ", y);
  print_binary(y);
  printf("\nz = %10d, which in binary is ", z);
  print_binary(z);
  printf("\n");

  return 0;
}
