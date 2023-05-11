#include "safe-fork.h"
#include "split.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_LEN 10000

/* David Perez
 * dperez7
 * 117915402
 * CMSC216 (0107) Project 9 yargs.c */

/* This program takes in a series of arguments and a series of inputs from
 * stdin. It then executes the arguments with the inputs as arguments. */
int main(int argc, char *argv[]) {
    char **all_args, **input_split;
    char *temp;
    pid_t pid;
    char input[MAX_LEN];
    int i, j, k, status, num_args, split_size, args_index;

    /* Check for -n flag */
    if (argc >= 2) {
        if (strcmp(argv[1], "-n") == 0) {
            num_args = argc - 2;
            args_index = 2;
        } else {
            num_args = argc - 1;
            args_index = 1;
        }
    }

    /* Read input until EOF is reached; data is stored in input buffer */
    while (fgets(input, MAX_LEN, stdin) != NULL) {

        /* Check for -n flag */
        if (args_index == 2) {
            for (i = args_index; i < argc; i++) {
                printf("%s ", argv[i]);
            }
            printf("%s", input);
        } else {
            pid = safe_fork();
            /* Parent process */
            if (pid > 0) {
                wait(&status); /* Wait for child process to finish */
            } else {
                /* Child process */
                split_size = 0;
                input_split = split(input);
                for (i = 0; input_split[i] != NULL; i++) {
                    split_size++;
                }

                /* Allocate memory for all arguments */
                all_args = malloc(sizeof(char *) * (num_args + split_size + 1));

                /* Copy arguments into all_args */
                k = 0;
                for (i = args_index; i < argc; i++) {
                    temp = malloc(sizeof(char) * (strlen(argv[i]) + 1));
                    strcpy(temp, argv[i]);
                    all_args[k] = temp;
                    k++;
                }

                /* Copy input into all_args */
                for (j = 0; j < split_size; j++) {
                    all_args[i + j - 1] = input_split[j];
                }
                /* Add NULL to end of all_args */
                all_args[split_size + num_args] = NULL;

                /* Execute all_args */
                execvp(all_args[0], all_args);
                exit(255);
            }

            /* Check if child process exited normally */
            if (WIFEXITED(status)) {
                if (WEXITSTATUS(status) != 0) {
                    exit(WEXITSTATUS(status));
                }
            } else {
                exit(255); /* Exit with error */
            }
        }
    }
    return 0;
}
