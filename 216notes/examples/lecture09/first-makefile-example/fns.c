#include <stdio.h>
#include "fns.h"

int product(int x, int y) {
  int i, result= 0;

  for (i= 1; i <= y; i++)
    result= sum(result, x);

  return result;
}

int sum(int x, int y) {
  return x + y;
}
