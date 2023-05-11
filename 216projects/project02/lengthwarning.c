#include <stdio.h>

/* David Perez
 * dperez7
 * 117915402
 * CMSC216 (0107) Project 2 lengthwarning.c
 *
 * This program will take an input and determine if it is
 * longer than 80 characters. The program will read one line
 * at a time and print an indication of whether the line
 * is longer than 80 characters or not. */

#define MAX_LINE_LENGTH 1000
#define CHAR_LIMIT 80

int main(void) {
    char input;
    /* char variable to be scanned and processed */
    char line[MAX_LINE_LENGTH];
    /* One-Dimensional array containing the input line being processed  */
    int line_number = 1;
    /* integer to keep track of how many lines have been processed */
    int i = 0;
    /* array index counter */
    int j;
    /* for-loop counter */
    int line_length = 0;
    /* integer to keep track of the character count */

    scanf("%c", &input); /* scans the first character */
    
    while (!feof(stdin)) {
	line[i] = input; /* adds character to array */
	if (line[i] == '\n') { 
	/* checks for newline character, which is the end of the line */
            if (line_length <= CHAR_LIMIT) {
                /* line is less than 80 characters, print it normally */
                printf(" ");
                printf("%5d: ",  line_number++);
		/* prints a space denoting short line, followed by the
		 * line number, padded with spaces to take up 5 characters */
                for (j = 0; j < line_length; j++) {
                    printf("%c", line[j]); /* prints line */
                }
                printf("\n");
            } else {
                /* line is too long, print it with an asterisk and carets */
                printf("*");
                printf("%5d: ",  line_number++);
                for (j = 0; j < i; j++) {
                    printf("%c", line[j]);
                }
                printf("\n        ");
		/* prints 8 blanks spaces to account for the length
		 * denotation and line number */
                for (j = 0; j < CHAR_LIMIT; j++) {
                    printf(" "); /* prints 80 spaces until carats start */
                }
                for (j = CHAR_LIMIT; j < line_length; j++) {
                    printf("^"); 
		    /* prints carats underneath every charcter excess 80 */
                }
                printf("\n");
            }
            i = 0, line_length = 0; 
	    /* reset array and character count for next line */
        } else { /* character is not a newline */
            if (line[i] == '\t') { /* handle tabs */
                line_length += 8 - (line_length % 8);
		/* adds spaces to reach 8-space tab mark */
                i++;
            } else { /* any other character */
                line_length++;
                i++;
            }
        }
	scanf("%c", &input);
    }
    return 0;
}

