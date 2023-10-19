#include "monty.h"

/**
 * addnode - adds a node to the stack
 * @stack: double pointer to the stack
 * @n: integer
 */

void addnode(stack_t **stack, int n)
{
	stack_t *tmp, *new_node;

	tmp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (tmp)
		tmp->prev = new_node;
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
