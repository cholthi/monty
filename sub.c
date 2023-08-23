#include "monty.h"

/**
 * instruction_sub - substracts top node from second top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void instruction_sub(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	instruction_pop(stack, line_number);
	(*stack)->n -= tmp;
}
