#include "monty.h"

/**
 * instruction_pchar - print char at top of stack
 * @stack: double pointer to top of stack
 * @line_number: what line in the monty bytecode file are we at?
 * Return: nothing
 **/
void instruction_pchar(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	if (!(i >= 0 && i <= 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(i);
	putchar('\n');
}
