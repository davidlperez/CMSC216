#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* David Perez
 * 117915402
 * CMSC216 (0107) Project 11 wc-threaded.c
 *
 * I pledge on my honor that I have not given or received any unauthorized
 * assistance on this assignment
 */

/* file_stats is a struct that contains the filename, number of lines, number
   of words, and number of characters in a file. */
typedef struct {
    char *filename;
    int lines;
    int words;
    int chars;
} file_stats;

/* process_file() takes a file_stats struct as an argument and fills in the
   lines, words, and chars fields with the appropriate values.  It then returns
   a pointer to the file_stats struct. */
void *process_file(void *arg) {
    file_stats *stats = arg;
    FILE *fp;
    char ch, next_ch;

    /* initialize the fields of the file_stats struct */
    stats->lines = 0;
    stats->words = 0;
    stats->chars = 0;

    /* open the file for reading */
    fp = fopen(stats->filename, "r");

    /* if the file exists, read it character by character and update the
       statistics */
    if (fp != NULL) {
        ch = fgetc(fp);
        while (!feof(fp)) {
            next_ch = fgetc(fp); /* look ahead and get the next character */
            ungetc(next_ch, fp); /* unread the next character */

            /* a newline means the line count increases */
            if (ch == '\n')
                stats->lines++;

            /* if the current character is not whitespace but the next character
               is, or if the current character is not whitespace and it is the
               last character in the input, the word count increases */
            if (!isspace(ch) && (isspace(next_ch) || feof(fp)))
                stats->words++;

            /* increasing the character count is a no-brainer */
            stats->chars++;

            ch = fgetc(fp);
        }

        fclose(fp); /* close the file */
    }
    return stats;
}

/* main() takes a list of filenames as command-line arguments and prints the
   total number of lines, words, and characters in all of the files combined.
   It creates a thread for each file, and each thread calls process_file() to
   get the statistics for its file.  The main thread waits for all of the
   threads to finish, then prints the totals. */
int main(int argc, char *argv[]) {
    pthread_t *threads;
    file_stats *stats, *value;
    void *retval; /* used to get the return value from process_file() */
    int i, total_lines = 0, total_words = 0, total_chars = 0, arg_num = 1;
    int num_threads = argc - 1;

    /* allocate memory for the threads and file_stats structs */
    threads = malloc(sizeof(pthread_t) * num_threads);
    stats = malloc(sizeof(file_stats) * num_threads);

    /* create a thread for each file */
    for (i = 0; i < num_threads; i++) {
        stats[i].filename = argv[arg_num++];

        /* create a thread for the file and pass it the file_stats struct */
        pthread_create(&threads[i], NULL, process_file, &stats[i]);
    }

    /* wait for all of the threads to finish */
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], &retval);
        value = retval;

        /* add the statistics for the file to the totals */
        total_lines += value->lines;
        total_words += value->words;
        total_chars += value->chars;
    }

    /* free the memory allocated for the threads and file_stats structs */
    free(threads);
    free(stats);
    
    /* print the totals */
    printf("%4d %4d %4d\n", total_lines, total_words, total_chars);

    return 0;
}
