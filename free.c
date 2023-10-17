#include "monty.h"

/**
 * free_stack - frees all malloc'd in stack
 *
 * Return: void
 */
void free_stack(void)
{
	stack_t *temp;
	stack_t *head;

	if (listx->stack)
	{
		head = listx->stack;

		while (head)
		{
			temp = head->next;
			free(head);
			head = temp;
		}
	}
}

/**
 * free_all - frees all malloc'd memory
 *
 * Return: void
 */
void free_all(void)
{
	if (listx != NULL)
	{
		if (listx->int_file != NULL)
			fclose(listx->int_file);

		if (listx->cmmd != NULL)
			free(listx->cmmd);

		if (listx->int_line != NULL)
			free(listx->int_line);

		free_stack();
		free(listx);
	}
}
