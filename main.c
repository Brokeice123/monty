#define _POSIX_C_SOURCE 200809L
#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	ssize_t read_line = 1;
	size_t size;
	FILE *file;
	char *line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &size, file);
		bus.content = line;
		line_number++;
		if (read_line > 0)
			execute(&stack, line, line_number, file);
		free(line);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}
