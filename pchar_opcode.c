#include "monty.h"

/**
 * pchar - Print the character at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode.
 */
void pchar(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)

	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->next->n);
}
