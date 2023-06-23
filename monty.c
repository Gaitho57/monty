#include "monty.h"

/*
 * Main function for the Monty interpreter.
 *
 * Parameters:
 *     argc: Number of command-line arguments.
 *     argv: Array of command-line argument strings.
 *
 * Returns:
 *     EXIT_SUCCESS if the program executes successfully, otherwise EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
    /* Verify the correct number of command-line arguments */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the specified file */
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Initialize variables for stack and line information */
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    char *line = NULL;
    size_t bufsize = 0;

    /* Read and process each line of the file */
    while (getline(&line, &bufsize, fp) != -1)
    {
        line_number++;
        tokenizer(line, &stack, line_number);
    }

    /* Close the file and free allocated memory */
    fclose(fp);
    free(line);
    free_stk(&stack, line_number);

    return EXIT_SUCCESS;
}

