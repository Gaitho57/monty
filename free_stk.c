#include "monty.h"

/*
 * Function: free_stk
 * ------------------
 * Frees the memory allocated for the stack.
 *
 * stack:          Pointer to the stack structure.
 * line_number:    The current line number being processed.
 *
 * Returns:        None.
 */
void free_stk(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
        return;

    stack_t *current = *stack;
    stack_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}

