# include "monty.h"

/**
 * add_node_lifo - adds a new node at the beginning of a stack_t list
 * @stack: head of stack (linked list)
 * @newn: the node to add
 *
 * Return: void
 */
void add_node_lifo(stack_t **stack, stack_t *newn)
{
	newn->prev = NULL;
	newn->next = *stack;
	if (*stack)
		(*stack)->prev = newn;
	*stack = newn;
}

/**
 * add_node_fifo - adds a new node at the end of a stack_t list
 * @stack: head of stack (linked list)
 * @newn: the node to add
 *
 * Return: void
 */
void add_node_fifo(stack_t **stack, stack_t *newn)
{
	stack_t *copy = *stack;

	newn->next = NULL;
	if (!*stack)
	{
		newn->prev = NULL;
		*stack = newn;
	}
	else
	{
		while (copy->next)
			copy = copy->next;
		copy->next = newn;
		newn->prev = copy;
	}
}

/**
 * h_push - adds a new node at the beginning of a stack_t list
 * @stack: head of stack (linked list)
 * @line_number: line number
 *
 * Return: void
 */
void h_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newn = NULL;
	char *num;
	(void)line_number;

	if (listx->cmmd[1] == NULL)
		err_msg(ERROR_PUSH);
	else
		num = listx->cmmd[1];
	if (check_digits(num) == TRUE)
	{
		newn = malloc(sizeof(stack_t));
		if (newn == NULL)
			err_msg(ERROR_MALLOC);
	}
	else
		err_msg(ERROR_PUSH);

	newn->n = atoi(num);
	if (listx->order == LIFO)
		add_node_lifo(stack, newn);
	else
		add_node_fifo(stack, newn);
}


/**
 * check_digits - checks if every char in a string is a digit
 * @num: number to check if all chars are digits
 *
 * Return: TRUE or FALSE
 */
int check_digits(char *num)
{
	int i;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] == '-' && i == 0)
			i++;
		if (isdigit(num[i]) == FALSE)
			return (FALSE);
	}

	return (TRUE);
}
