#include "monty.h"
/**
 * stack_op - this function sets the format of data
 *            to a stack
 * @hd: points to the head of the list
 * @linenum: this is the line no the error checks with
 *
 * Return: Nothing
 */

void stack_op(stack_t **hd, unsigned int linenum)
{
	(void)linenum;
	(void)hd;

	vexec.lifo = 1;
}

/**
 * queue_op - this here sets the format of data to queue
 *     which is FIFO
 * @hd: points to the head of the list
 *
 * @linenum: the specific line no the erros references
 *
 * Return: Nothing
 */

void queue_op(stack_t **hd, unsigned int linenum)
{
	(void)linenum;
	(void)hd;

	vexec.lifo = 0; /*FIFO*/
}
