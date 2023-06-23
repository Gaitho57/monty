#include "monty.h"

/*
 * Function: tokenizer
 * -------------------
 * Tokenizes a line of instructions and calls the corresponding function for each token.
 *
 * line:           The line of instructions to tokenize.
 * stack:          Pointer to the stack structure.
 * line_number:    The current line number being processed.
 *
 * Returns:        None.
 */
void tokenizer(char *line, stack_t **stack, unsigned int line_number)
{
    char *token = strtok(line, " \t\n");
    if (token == NULL || token[0] == '#')
        return;

    findOps(token, stack, line_number);
}

/*
 * Function: findOps
 * -----------------
 * Searches for the corresponding function based on the given token and calls it.
 *
 * token:          The instruction token to find and execute.
 * stack:          Pointer to the stack structure.
 * line_number:    The current line number being processed.
 *
 * Returns:        None.
 */
void findOps(char *token, stack_t **stack, unsigned int line_number)
{
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        // Add more opcodes and their corresponding functions here
        {NULL, NULL}
    };

    int i = 0;
    while (ops[i].opcode != NULL)
    {
        if (strcmp(token, ops[i].opcode) == 0)
        {
            ops[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
    free_stk(stack, line_number);
    exit(EXIT_FAILURE);
}

