#ifndef _MONTY_H_
#define _MONTY_H_

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


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
 * struct execution -  struct to use in the execution
 * in the specific functions
 * @lifo: whether it is a queue or stack
 * @currline: the current line
 * @arg: the argument in the specific line we are in
 * @head: the start of thedoubly linked list
 * @fd: the file structure for input/output
 * @buff: this is used to hold the inputed text
 */
typedef struct execution
{
	unsigned int currline;
	int lifo;
	char  *arg;
	FILE *fd;
	stack_t *head;
	char *buff;
} exec_t;

extern exec_t vexec;

/**
 * struct customdata - struct that carries values in prog
 *
 * @file: points to FILE to handle operatioms
 * @arg: a char pt representing value
 * @text: what is in the line
 * @lifi: switch of flag stack <-> queue
 */
typedef struct customdata
{
	FILE *file;
	char *arg;
	char *text;
	int lifi;
}  customdata_t;
extern customdata_t mydata;


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

void mul_op(stack_t **hd, unsigned int linenum);
char *string_tok(char *st, char *d);
int _strcmp_(char *st1, char *st2);
void free_dlist(stack_t *head);
stack_t *add_node_end(stack_t **hd, const int n);
stack_t *add_nodebegin(stack_t **hd, const int n);
void _pushstck(stack_t **hd, unsigned int linenum);
void _pallstck(stack_t **hd, unsigned int linenum);
void pint_op(stack_t **hd, unsigned int linenum);
void pop_op(stack_t **hd, unsigned int linenum);
void op_swap(stack_t **doubly, unsigned int linenum);
void div_op(stack_t **hd, unsigned int linenum);
void sub_op(stack_t **hd, unsigned int linenum);
void nop_op(stack_t **hd, unsigned int linenum);
void add_two(stack_t **hd, unsigned int linenum);
void mul_op(stack_t **hd, unsigned int linenum);
void _pstr(stack_t **hd, unsigned int linenum);
void _printch(stack_t **hd, unsigned int linenum);
void _modulus(stack_t **hd, unsigned int linenum);
void rot_rev(stack_t **hd, unsigned int linenum);
void rot_top(stack_t **hd, unsigned int linenum);
void stack_op(stack_t **hd, unsigned int linenum);
int main(int argc, char *argv[]);
void queue_op(stack_t **hd, unsigned int linenum);
FILE *find_file(int argc, char *argv[]);
void init_exec(FILE *fd);
void free_exec(void);
void (*find_opcodes(char *opcd))(stack_t **stack, unsigned int line_number);
int get_ch(char *str, char c);

#endif
