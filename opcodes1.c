# include "monty.h"

/**
 * h_pall - prints all the elements from the stack
 * @stack: head of stack
 * @line_number: line number
 *
 * Return: void
 */
void h_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;
	(void)line_number;

	for (copy = *stack; copy; copy = copy->next)
		printf("%d\n", copy->n);
}

/**
 * h_pint - prints the number of the head node
 * @stack: the stack
 * @line_number: line number
 * Return: None
 */
void h_pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!stack || !*stack)
		err_msg(ERROR_PINT);

	printf("%d\n", (*stack)->n);
}

/**
 * h_pop - pop the top element off the stack, i.e. remove head
 * @stack: head of stack (linked list)
 * @line_number: line number
 *
 */
void h_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;
	(void)line_number;

	if (*stack == NULL)
		err_msg(ERROR_POP);
	else if ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		next->prev = NULL;
		free(*stack);
		*stack = next;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * h_swap - swap the top two elements
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void h_swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		err_msg(ERROR_SWAP);

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
