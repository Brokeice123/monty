#include "monty.h"

/**
 * op_mod - performs modulus operation
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;

	if (tmp->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = tmp->next->n % tmp->n;
	tmp->next->n = n;

	*stack = tmp->next;
	free(tmp);
}
