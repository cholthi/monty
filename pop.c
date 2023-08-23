#include "monty.h"

/**
 * instruction_pop - removes top element of stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void instruction_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node  = *stack;
	(*stack) = (*stack)->next;
	free(node);
}
