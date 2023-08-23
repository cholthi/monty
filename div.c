#include "monty.h"

/**
 * instruction_div - divides second top node from top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void instruction_div(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	if (tmp == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	instruction_pop(stack, line_number);
	(*stack)->n /= tmp;
}
