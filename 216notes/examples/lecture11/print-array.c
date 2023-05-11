#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* has a function that prints an array, using pointer arithmetic */

static void print_array(const int a[], int sz);

/* The lecture slides have a more concise version of this
 * function.  If you want to see the pointers printed
 * also, uncomment the first printf() and comment out the
 * second one.
 */
void print_array(const int a[], int sz) {
  const int *ptr;

  for (ptr= a; ptr < &a[sz]; ptr++) {
    /* if you uncomment the first printf(), what happens
     * to the memory addresses of the array elements
     * every time you run the program?
     */
    /* printf("%p %d\n", (void *) ptr, *ptr); */
    printf("%d ", *ptr);
  }

  printf("\n");
}


int main(void) {
  int arr1[]= {2, 0, 2, 2};
  int arr2[]= {3, 6, 8, 2, 9, 4, 1, 5, 7};

  print_array(arr1, 4);
  print_array(arr2, 9);

  return 0;
}
