#ifndef MONTY
#define MONTY

/* ----- c std lib headers ----- */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

/* ----- macros ----- */

#define TRUE (1 == 1)
#define FALSE (!TRUE)
#define BUFSIZE 1024
#define LIFO 1
#define FIFO 0

/* ----- ERRORS ----- */

#define ERROR_MALLOC 0
#define ERROR_USAGE_FILE 1
#define ERROR_OPEN_FILE 2
#define ERROR_UNKNOWN 3
#define ERROR_PUSH 4
#define ERROR_PINT 5
#define ERROR_POP 6
#define ERROR_SWAP 7
#define ERROR_ADD 8
#define ERROR_SUB 9
#define ERROR_DIV 10
#define ERROR_DIV_ZERO 11
#define ERROR_MUL 12
#define ERROR_MOD 13
#define ERROR_STACK_EMPTY 14
#define ERROR_PCHAR_RANGE 15

/* ----- Structs ----- */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct inventory_s - a struct pointing to all other structs for this project
 * @filename: the filename from argv[1]
 * @stack: pointer to stack
 * @int_line: input line received from getline
 * @cmmd: lines of the files parsed into separate elements
 * @line_count: the linenumber
 * @int_file: the input file
 * @order: LIFO or FIFO, stack or queue
 */
typedef struct inventory_s
{
	char *filename;
	stack_t *stack;
	char *int_line;
	char **cmmd;
	unsigned int line_count;
	FILE *int_file;
	int order;
} inventory_t;

/* ----- global ----- */

extern inventory_t *listx;
inventory_t *listx;

/* ------Built Inventory -------*/

int built_listx(void);

/* ----- Add to Stack ----- */

void add_node_lifo(stack_t **stack, stack_t *newn);
void add_node_fifo(stack_t **stack, stack_t *newn);
void h_push(stack_t **stack, unsigned int line_number);

/* ----- opcodes ----- */

void h_pall(stack_t **stack, unsigned int line_number);
void h_pint(stack_t **stack, unsigned int line_number);
void h_pop(stack_t **stack, unsigned int line_number);
void h_swap(stack_t **stack, unsigned int line_number);

/* ----- Fetch_opcodes ------ */

void (*fetch_opcode(void))(stack_t **stack, unsigned int line_number);
int parser(char *int_line);
void err_msg(int e);
int check_digits(char *num);

/* ----- Free ----- */

void free_all(void);
void free_stack(void);



#endif
