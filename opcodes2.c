#include "monty.h"

/**
 * h_mod - computes the rest of the division of the second top element of the
 *        stack by the top element of the stack.
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void h_mod(stack_t **stack, unsigned int line_number)
{
	int rem;

	if (*stack == NULL || (*stack)->next == NULL)
		err_msg(ERROR_MOD);

	if ((*stack)->n == 0)
		err_msg(ERROR_DIV_ZERO);

	rem = (*stack)->next->n % (*stack)->n;

	h_pop(stack, line_number);
	(*stack)->n = rem;
}

/**
 * h_pchar - prints the char type of the head node integer
 * @stack: the stack
 * @line_number: line number
 *
 * Return: None
 */
void h_pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!stack || !*stack)
		err_msg(ERROR_STACK_EMPTY);

	if ((*stack)->n < 0 || (*stack)->n > 127)
		err_msg(ERROR_PCHAR_RANGE);

	printf("%c\n", (*stack)->n);
}

/**
 * h_pstr - prints the str type of the head node integer
 * @stack: the stack
 * @line_number: line number
 *
 * Return: None
 */
void h_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;

	(void)line_number;

	for (copy = *stack; copy; copy = copy->next)
	{
		if (copy->n < 1 || copy->n > 127)
			break;
		printf("%c", copy->n);
	}
	_putchar('\n');
}

/**
 * h_rotl - rotates the stack top to bottom
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void h_rotl(stack_t **stack, unsigned int line_number)
{
	int end;
	stack_t *copy;

	(void)line_number;

	if (stack && *stack)
	{
		end = (*stack)->n;

		for (copy = *stack; copy->next; copy = copy->next)
			copy->n = copy->next->n;
		copy->n = end;
	}
}

/**
 * h_rotr - rotates the stack bottom to top
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void h_rotr(stack_t **stack, unsigned int line_number)
{
	int next, current;
	stack_t *copy;

	(void)line_number;

	if (stack && *stack)
	{
		copy = *stack;
		next = copy->n;

		while (copy->next)
		{
			current = next;
			next = copy->next->n;
			copy->next->n = current;
			copy = copy->next;
		}
		(*stack)->n = next;
	}
}
