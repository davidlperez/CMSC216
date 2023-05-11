#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* illustrates treating an array name as a pointer, and applying pointer
   arithmetic operations to it */

int main(void) {
  int i, arr[5]= {10, 20, 30, 40, 50};
  int *p;

  p= &arr[2];
  *p= 60;
  p= arr;
  *p= 70;

  for (i= 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");

  arr[4]= *(arr + 3);
  *(arr + 3)= 80;
  arr[1]= &arr[4] - arr;

  for (i= 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");

  /* arr++; */  /* what's wrong with this one? */
  /* *(arr + 5)= 100; */  /* what's wrong with this one? */
  /* *(arr - 1)= 200; */  /* what's wrong with this one? */

  return 0;
}
