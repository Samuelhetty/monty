#include "monty.h"

/**
 * built_listx - builds global struct of most used variables
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int built_listx(void)
{
	listx = malloc(sizeof(inventory_t));
	if (!listx)
		err_msg(ERROR_MALLOC);

	listx->cmmd = malloc(sizeof(char *) * 3);
	if (!listx->cmmd)
	{
		free(listx);
		err_msg(ERROR_MALLOC);
	}

	listx->stack = NULL;
	listx->int_line = NULL;
	listx->line_count = 0;
	listx->order = LIFO;

	return (EXIT_SUCCESS);
}

/**
 * err_msg - function to handle all errors
 * @e: index number of error message
 *
 * Return: void
 */
void err_msg(int e)
{
	unsigned int n;
	static char *const errors[] = {
		"Error: malloc failed\n", "USAGE: monty file\n",
		NULL, NULL,
		"usage: push integer\n", "can't pint, stack empty\n",
		"can't pop an empty stack\n", "can't swap, stack too short\n",
		"can't add, stack too short\n", "can't sub, stack too short\n",
		"can't div, stack too short\n", "division by zero\n",
		"can't mul, stack too short\n", "can't mod, stack too short\n",
		"can't pchar, stack empty\n", "can't pchar, value out of range\n"
	};

	if (listx)
		n = listx->line_count;

	if (e <= 1)
		dprintf(STDOUT_FILENO, "%s", errors[e]);
	else if (e == 2)
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n",
				listx->filename);
	else if (e == 3)
		dprintf(STDOUT_FILENO, "L%u: unknown instruction %s\n", n,
				listx->int_line[0]);
	else if (e >= 4)
		dprintf(STDOUT_FILENO, "L%u: %s", n, errors[e]);

	free_all();

	exit(EXIT_FAILURE);
}
