#include "monty.h"

/**
 * instruction_mod - computes modulo of div of 2nd by top element
 * @stack: double pointer to top of stack
 * @line_number: what line in the monty bytecode file are we at?
 * Return: nothing
 **/
void instruction_mod(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	if (tmp == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	instruction_pop(stack, line_number);
	(*stack)->n %= tmp;
}
