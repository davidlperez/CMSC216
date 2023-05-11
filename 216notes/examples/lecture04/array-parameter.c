#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* Shows a function with an array parameter.  The (entire) array arr in
 * main() is passed into the function's parameter a.  The function modifies
 * the elements of its parameter a.  What happens to arr in main()?
 *
 * Any size array array can be passed into a function's array parameter
 * (like a).  But what limitation does the function incr_array() have?
 */

static void incr_array(int a[]);

static void incr_array(int a[]) {
  int size= 5;

  size--;

  while (size >= 0) {
    a[size]++;
    size--;
  }
}

int main(void) {
  int i, arr[5]= {-2, -1, 0, 1, 2};

  incr_array(arr);
  for (i= 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
