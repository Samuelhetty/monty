#include "monty.h"

/**
 * h_add - add two numbers from the top of that stack
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void h_add(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
		err_msg(ERROR_ADD);

	total = (*stack)->n + (*stack)->next->n;
	h_pop(stack, line_number);
	(*stack)->n = total;
}

/**
 * h_nop - does not print, do not pass go, do not collect $200
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void h_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * h_sub - subtracts the top element of the stack from the second top
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void h_sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	if (*stack == NULL || (*stack)->next == NULL)
		err_msg(ERROR_SUB);

	diff = (*stack)->next->n - (*stack)->n;

	h_pop(stack, line_number);
	(*stack)->n = diff;
}

/**
 * h_div - divides the second top element of the stack by the top element
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void h_div(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
		err_msg(ERROR_DIV);

	if ((*stack)->n == 0)
		err_msg(ERROR_DIV_ZERO);

	quotient = (*stack)->next->n / (*stack)->n;

	h_pop(stack, line_number);
	(*stack)->n = quotient;
}

/**
 * h_mul - multiplies the second top element of the stack with the top
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void h_mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
		err_msg(ERROR_MUL);

	product = (*stack)->next->n * (*stack)->n;

	h_pop(stack, line_number);
	(*stack)->n = product;
}
