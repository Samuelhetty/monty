#include "monty.h"

/**
 * main - main function for monty program
 * @argc: arguments count
 * @argv: arguments inventory (file path expected)
 *
 * Return: 0 always - success!
 */
int main(int argc, char **argv)
{
	size_t n;
	void (*execute)(stack_t **stack, unsigned int line_number);

	listx = NULL;
	if (argc != 2)
		err_msg(ERROR_USAGE_FILE);

	built_listx();
	listx->filename = argv[1];
	listx->int_file = fopen(listx->filename, "r");

	if (listx->int_file == NULL)
		err_msg(ERROR_OPEN_FILE);

	while (getline(&listx->int_line, &n, listx->int_file) > 0)
	{
		listx->line_count++;

		if (parser(listx->int_line) == EXIT_FAILURE)
			continue;

		execute = fetch_opcode();
		execute(&listx->stack, listx->line_count);
	}
	free_all();
	return (EXIT_SUCCESS);
}
