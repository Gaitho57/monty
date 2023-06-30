#include "monty.h"
/**
* free_stack - breaks free a doubly linked list
* @head: header for the stack
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
