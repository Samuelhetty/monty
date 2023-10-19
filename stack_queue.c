#include "monty.h"

/**
 * h_stack - switches to stack to LIFO
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void h_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	listx->order = LIFO;
}

/**
 * h_queue - switches to queue FIFO
 * @stack: the stack
 * @line_number: line number
 *
 * Return: None
 */
void h_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	listx->order = FIFO;
}

/**
  * _putchar - writes the character c to stdout
  * @c: the char to print
  *
  * Return: on success 1
  * on error, -1 is returned, and error is set appropraitely
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
