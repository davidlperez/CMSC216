#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Demonstrates using a symbolic constant, for an array's dimension in this
 * example.  What's the advantage of using a symbolic constant for the
 * array's size?
 */

#define SIZE 8

static void incr_array(int a[]);

static void incr_array(int a[]) {
  int num= SIZE - 1;

  while (num >= 0) {
    a[num]++;
    num--;
  }
}

int main(void) {
  int i, arr[SIZE]= {-2, -1, 0, 1, 2};

  incr_array(arr);

  for (i= 0; i < SIZE; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
