#include <stdio.h>
#include "fns.h"

int main() {
  printf("sum(2, 5) is %d.\n", sum(2, 5));
  printf("sum(2, -7) is %d.\n", sum(2, -7));

  printf("\nproduct(1, 2) is %d.\n", product(1, 2));
  printf("product(4, 9) is %d.\n", product(4, 9));
  printf("product(3, 5) is %d.\n", product(3, 5));

  return 0;
}
