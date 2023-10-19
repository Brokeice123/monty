#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void push(stack_t **stack, unsigned int line_number)
{
	int n, i = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] < '0' || bus.arg[i] > '9')
				flag = 1;

		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(stack, n);
	else
		addqueue(stack, n);
}

/**
 * pall - prints all the values in the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	printf("%d\n", tmp->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	if (tmp->next)
	{
		*stack = tmp->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		*stack = NULL;
		free(tmp);
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	n = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = n;
}
