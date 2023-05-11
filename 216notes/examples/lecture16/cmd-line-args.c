#include <stdio.h>
#include <string.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* This program just reads some nonnegative integers from its standard input
 * and tests whether they are in order.  If there are more than 1000
 * integers only the first 1000 are read.  Where command-line arguments come
 * in is that if the argument -r used the numbers are tested to see if they
 * are in reverse (descending) order, while -a (which is the default), means
 * ascending order.  If more than one of these arguments are given the last
 * one on the command line is used.  And the user can enter numbers either
 * in decimal or in hexadecimal.  The command-line argument -h tells the
 * program to read hexadecimal numbers, while -d which is the default) means
 * it should read numbers in decimal.  And f more than one of these
 * arguments are given the last one on the command line is used.
 *
 * Note that this problem does not require arrays to be used at all.  We
 * could just read numbers and compare each number to the previous one, only
 * requiring two int variables, instead of an an entire int array.  I used
 * an array just to demonstrate another application of function pointers,
 * where the same function is_in_order() can easily test for the array being
 * in either ascending or descending order, without special cases, by just
 * passing one of two different comparison functions into its function
 * pointer parameter.
 */

#define MAX 1000

enum base {DECIMAL, HEXADECIMAL};

static int read_int(enum base which_base);
static int read_numbers(int arr[], enum base which_base);
static short is_in_order(int arr[], int num_elts, int (*compare_fn)(int, int));
static int ascending(int a, int b);
static int descending(int a, int b);

static int read_int(enum base which_base) {
  unsigned int n;
  int result;
  
  if (which_base == HEXADECIMAL) {
    scanf("%x", &n);
    result= n;
  } else
    scanf("%d", &result);  /* which_base == DECIMAL */

  return result;
}

/* reads up to 1000 numbers from the standard input, stores them in arr, and
 * returns how many numbers were read
 */
int read_numbers(int arr[], enum base which_base) {
  int n, count= 0;

  n= read_int(which_base);
  while (!feof(stdin) && count < MAX) {
    arr[count++]= n;
    n= read_int(which_base);
  }

  return count;
}

/* returns 1 if the elements of arr, which has num_elts elements, are all in
 * order, where in-order could be ascending order or descending order.  The
 * user specified which comparison they want performed by passing a pointer
 * to an appropriate function used to compare adjacent pairs of elements,
 * into the parameter compare_fn.
 */
short is_in_order(int arr[], int num_elts, int (*compare_fn)(int, int)) {
  int i= 1, result= 1;

  /* an array with zero element or 1 element is trivially in order, so the
     loop will only execute if num_elts is 2 or more */
  while (i < num_elts && result == 1)
    if (compare_fn(arr[i - 1], arr[i]) == 1)
      i++;
    else result= 0;

  return result;
}

/* returns 1 if a is less than or equal to b, and 0 otherwise */
int ascending(int a, int b) {
  return a <= b;
}

/* returns 1 if b is less than or equal to a, and 0 otherwise */
int descending(int a, int b) {
  return b <= a;
}

int main(int argc, char *argv[]) {
  int array[MAX]= {0};
  enum mode {ASCENDING, DESCENDING};
  enum mode order= ASCENDING;
  enum base base_to_use= DECIMAL;  /* default */
  int i= 1, num_read, valid= 1, answer;

  while (i < argc && valid) {
    if (strcmp(argv[i], "-r") == 0)
      order= DESCENDING;
    else
      if (strcmp(argv[i], "-a") == 0)
        order= ASCENDING;
      else
        if (strcmp(argv[i], "-h") == 0)
          base_to_use= HEXADECIMAL;
        else
          if (strcmp(argv[i], "-d") == 0)
            base_to_use= DECIMAL;
          else valid= 0;

    if (valid)
      i++;
  }

  if (!valid) {
    printf("Invalid/unknown command-line argument \"%s\".  ", argv[i]);
    printf("(Please try harder you dope.)\n");
  } else {
    num_read= read_numbers(array, base_to_use);

    answer= is_in_order(array, num_read,
                        (order == ASCENDING ? &ascending : &descending));
    printf("The array's elements are%s in %s order.\n",
           (answer ? "" : " not"),
           (order == ASCENDING ? "ascending" : "descending"));
  }

  return 0;
}
