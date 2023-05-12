#include <stdio.h>
#include <stdlib.h>

static unsigned long fib(unsigned int n);

/* returns the nth Fibonacci number, using iteration (fib(0) = fib(1) = 1) */
static unsigned long fib(unsigned int n) {
  unsigned long a= 0, b= 1;

  while (n-- > 0) {
    unsigned long c= a + b;
    a= b;
    b= c;
  }

  return b;
}

int main(int argc, char *argv[]) {
  int num;

  if (argc != 2) {
    printf("The required command-line argument is the number to calculate\n");
    printf("the Fibonacci function of.\n");
    exit(-1);
  } else {
    num= atoi(argv[1]);
    printf("%lu\n", fib(num));
  }

  return 0;
}
