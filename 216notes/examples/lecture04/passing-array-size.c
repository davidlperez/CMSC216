#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Illustrates passing an array's size as an additional argument to a
 * function.  The function incr_any_array() is passed two different sized
 * arrays, with their sizes.  Why is this a common paradigm in C?
 */

static void incr_any_array(int a[], int size);
static void print_any_array(int a[], int size);

static void incr_any_array(int a[], int size) {
  size--;
  while (size >= 0) {
    a[size]++;
    size--;
  }
}

static void print_any_array(int a[], int size) {
  int i;

  for (i= 0; i < size; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main(void) {
  int arr1[5]= {-2, -1, 0, 1, 2};
  int arr2[7]= {6, 5, 4, 3, 2, 1, 0};

  incr_any_array(arr1, 5);
  incr_any_array(arr2, 7);

  print_any_array(arr1, 5);
  print_any_array(arr2, 7);

  return 0;
}
