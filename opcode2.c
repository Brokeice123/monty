#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	n = tmp->n + tmp->next->n;
	tmp->next->n = n;

	*stack = tmp->next;
	free(tmp);
}

/**
 * nop - does nothing
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	n = tmp->next->n - tmp->n;
	tmp->next->n = n;

	*stack = tmp->next;
	free(tmp);
}

/**
 * op_div - divides the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = tmp->next->n / tmp->n;
	tmp->next->n = n;

	*stack = tmp->next;
	free(tmp);
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	n = tmp->next->n * tmp->n;
	tmp->next->n = n;

	*stack = tmp->next;
	free(tmp);
}
