#include "monty.h"

/**
 * process_file - process the whole monty file
 * @filename: str name of monty opcode file
 * @stack: double pointer to top of stack data struct
 * Return: return an error code or success
 **/
int process_file(char *filename, stack_t **stack)
{
	size_t len;
	ssize_t read;
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fp;
	char *op;


	if (!filename)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	atexit(free_all);
	while ((read = getline(&line, &len, fp) != -1))
	{
		op = strtok(line, DELIMS);
		line_number++;
		if (op)
			delegate_op(stack, op, line_number);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
