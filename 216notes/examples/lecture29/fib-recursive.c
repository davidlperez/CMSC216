#include <stdio.h>
#include <stdlib.h>

/* returns the nth Fibonacci number, calculated recursively (fib(0) = fib(1)
   = 1) */

static unsigned long fib(unsigned int n);

static unsigned long fib(unsigned int n) {
  if (n == 0 || n == 1)
    return 1;
  else return fib(n - 1) + fib(n - 2);
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
