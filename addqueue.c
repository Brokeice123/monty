#include "monty.h"

/**
 * addqueue - adds a node to the queue
 * @queue: double pointer to the queue
 * @n: integer
 */

void addqueue(stack_t **queue, int n)
{
	stack_t *tmp, *new_node;

	tmp = *queue;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}

	if (!tmp)
	{
		*queue = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}
