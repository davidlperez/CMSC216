#include <stdio.h>

/* David Perez
 * dperez7
 * 117915402
 * CMSC216 (0107) Project 2 problemlines.c
 *
 * This program takes the output of lengthwarning.c
 * and condenses it by just printing the line numbers
 * of the lines that are too long. */

#define MAX_LINES 99999
int main(void) {

    char input;
    /* character scanned from input */
    int lines[MAX_LINES];
    /* array of lines numbers with max size of 99999 */
    int i = 0; /* array index counter */
    int j; /* for-loop counter */
   
    while (!feof(stdin)) {
	scanf("%c", &input);

	if (input == '*') {
	/* if first character is an asterisk,
         * the line number will be scanned and added to array */
	    scanf("%d", &lines[i++]);
	    for (j = 0; j < 2; j++) {
	    /* since longer lines print an output of 2 lines,
	     * this loops through them until the next input is reached */
		while (input != '\n') {
		    scanf("%c", &input);
		}
	    }   	
	} else { /* not an asterisk */
	/* loops through line and does nothing since no problem */
	    while (input != '\n') {
	   	scanf("%c", &input);
	    }
	}
    }

    for (j = 0; j < i; j++) {
    /* loops through and prints the line numbers followed by a space,
     * with an excpetion of the last line, which does not have a space */
	if (j == (i - 1)) {
	    printf("%d", lines[j]);
	} else {
	    printf("%d ", lines[j]);
	}
    }

    printf("\n");

    return 0;
}
