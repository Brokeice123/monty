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


/**
 * commenting - function that enables monty to comment
 * @stack: stack to sort through
 * @line_number: line number
 * @line: line
 */

void commenting(char *line, unsigned int line_number, stack_t **stack)
{
	char *trimmed_line = trim(line);

	if (strlen(trimmed_line) == 0)
	{
		return;
	}

	if (trimmed_line[0] == '#')
	{
		return;
	}

	char *opcode = strtok(trimmed_line, " \t\n\r");

	if (opcode != NULL)
	{
		execute_opcode(opcode, stack, line_number);
	}

