#include "monty.h"

/**
 * fetch_opcode - function to handle opcodes and their paired functions
 *
 * Return: function needed
 */

void (*fetch_opcode(void))(stack_t **stack, unsigned int line_number)
{
	char *int_opcode;
	instruction_t *i;
	static instruction_t instructions[] = {
		{"push", h_push}, {"pall", h_pall},
		{"pint", h_pint}, {"pop", h_pop}, {"swap", h_swap},
		{NULL, NULL}
	};

	i = instructions;
	int_opcode = listx->cmmd[0];

	while (i->opcode && strncmp(i->opcode, int_opcode, strlen(int_opcode)))
		i++;

	if (!i->f)
		err_msg(ERROR_UNKNOWN);

	return (i->f);
}

/**
 * parser - parses line/getline into input global variable
 * @int_line: input line
 *
 * Return: void
 */

int parser(char *int_line)
{
	char *delim, *s;
	int len, i;

	delim = "\n ";
	s = listx->int_line;
	len = strlen(s);

	for (i = 0; s[i] == delim[0] || s[i] == delim[1]; i++)
		;
	if (i == len)
		return (EXIT_FAILURE);

	listx->cmmd[0] = strtok(int_line, delim);

	if (listx->cmmd[0][0] == '#')
		return (EXIT_FAILURE);

	listx->cmmd[1] = strtok(NULL, delim);

	return (EXIT_SUCCESS);
}
