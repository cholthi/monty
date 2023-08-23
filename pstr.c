#include "monty.h"

/**
 * instruction_pstr - prints out string starting from top of stack
 * @stack: double pointer to top of stack
 * @line_number: what line in the monty bytecode file are we at?
 **/
void instruction_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	UNUSED(line_number);
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (isascii(tmp->n) && tmp->n != 0)
			putchar(tmp->n);
		else
			break;
		tmp = tmp->next;
	}
	putchar('\n');
}
