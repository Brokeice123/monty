#include "monty.h"

/**
 * execute - execute the opcode
 * @stack: double pointer to the stack
 * @line: pointer to the line
 * @line_number: line number of the file
 * @file: pointer to the file
 *
 * Return: 0 on success, 1 on failure
 */

int execute(stack_t **stack, char *line, unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", op_div},
		{"mul", mul},
		{NULL, NULL}
	};

	unsigned int j = 0;
	char *op;

	op = strtok(line, " \n\t");
	if (op && op[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");
	while (opst[j].opcode && op)
	{
		if (strcmp(op, opst[j].opcode) == 0)
		{
			opst[j].f(stack, line_number);
			return (0);
		}
		j++;
	}
	if (op && opst[j].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
