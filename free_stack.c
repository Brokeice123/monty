#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: double pointer to the stack
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	tmp = stack;
	while (stack)
	{
		stack = stack->next;
		free(tmp);
		tmp = stack;
	}
}
