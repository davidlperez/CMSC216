#include <stdio.h>
#include <stdlib.h>

static unsigned long fib(unsigned int n);

/* returns the nth Fibonacci number, using memoization, where 0 <= n < 100
 * (fib(0) = fib(1) = 1) (the table size of 100 imposes the limit of 100)
 */
static unsigned long fib(unsigned int n) {
  static unsigned long table[100]= {0};

  if (n == 0 || n == 1)
    return 1;
  else
    if (table[n] != 0)
      return table[n];
    else return table[n]= fib(n - 1) + fib(n - 2);
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
