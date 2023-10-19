#include "monty.h"
/**
 * pstr- function that prints the string at top of stack
 * @stack: stack that contains string
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	char *str = NULL;
	int str_len = 0;

	while (current != NULL && current->n != 0
			&& current->n >= 0 && current->n <= 127)
	{
		str_len++;
		str = realloc(str, str_len);
		if (str == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		str[str_len - 1] = current->n;
		current = current->next;
	}

	str = realloc(str, str_len + 1);
	if (str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	str[str_len] = '\0';
	if (str_len > 0)
	{
		fprintf(stdout, "%s\n", str);
	}
	free(str);
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
}
