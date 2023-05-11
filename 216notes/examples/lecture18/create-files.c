#include <stdio.h>
#include <assert.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* A short program that creates a text file and writes some data to it (20
 * ints and 10 floats) and then creates a binary file and writes the same
 * numbers to it.  We will see that the text file that is created is human
 * readable but the binary file is not (unless you are a rather unusual
 * human).  The terminal program tries to interpret the bytes of the ints
 * and floats in the binary file as characters, but many of the bytes do not
 * represent valid ASCII characters.
 *
 * Note that different terminal programs display non-ASCII characters
 * differently (they have no standard printed representation).
 */

#define SIZE1 20
#define SIZE2 10

int main(void) {
  int arr1[]= {221, 374, 376, 220, 119, 45, 270, 16, 221, 171, 442, 146,
               212, 499, 142, 206, 86, 427, 321, 81};  /* random ints */
  float arr2[]= {403.232, 261.214, 454.39, 135.454, 408.192, 385.181,
                 147.308, 32.272, 100.251, 476.4};  /* random floats */
  FILE *fp;
  int i;

  /* create a text file and write the ints and floats to it */
  fp= fopen("text-file", "w");

  for (i= 0; i < SIZE1; i++)
    fprintf(fp, "%d", arr1[i]);
  for (i= 0; i < SIZE2; i++)
    fprintf(fp, "%f", arr2[i]);

  fclose(fp);

  /* now create a binary file and write the same data to it */
  fp= fopen("binary-file", "wb");

  fwrite(arr1, sizeof(arr1[0]), SIZE1, fp);
  fwrite(arr2, sizeof(arr2[0]), SIZE2, fp);

  fclose(fp);

  return 0;
}
