#include "monty.h"

/**
 * pchar - Print the character at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the opcode.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)

	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((char)value);
	putchar('\n');
}
