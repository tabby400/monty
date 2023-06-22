#include "monty.h"

/**
 * add_two - function used to add two top elements in
 *          a stack top element has the result
 * @hd: this points to the head of the linked list which
 *      points to the linked list itself
 * @linenum: the specific line number where the error
 *              uses to reference
 * Return: Nothing
 */

void add_two(stack_t **hd, unsigned int linenum)
{
	int nd = 0;
	stack_t *temp = NULL;

	temp = *hd;/* now points to first node*/

	for ( ; temp != NULL ; temp = temp->next, nd++)
		;

	if (nd < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}

	temp = (*hd)->next;
	temp->n =  temp->n + (*hd)->n;
	pop_op(hd, linenum);
}

/**
 * nop_op - function or instruction which does not
 *          do a thing
 * @hd: points to the head of the linked list
 * @linenum: where the error can reference
 *
 * Return: Nothing
 */
void nop_op(stack_t **hd, unsigned int linenum)
{
	(void)linenum;
	(void)hd;
}

/**
 * sub_op - function that subtracts the top element of the
 * given stack from the second top element
 *
 * @hd: points to he head of the linked list
 * @linenum: this is where the error references
 *
 * Return: Nothing
 */
void sub_op(stack_t **hd, unsigned int linenum)
{
	int nd = 0;
	stack_t *now;

	now = *hd; /*points to first node*/

	for ( ; now != NULL ; now = now->next, nd++)
		;

	if (nd < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}

	now = (*hd)->next;
	now->n = now->n - (*hd)->n;
	pop_op(hd, linenum);
}

/**
 * div_op - this function divides the second top most element
 * in a given stack by the top most element
 *
 * @hd: points to the head of the linked list which points to first
 *      element in the list
 * @linenum: this is the line no the error wil check with
 *
 * Return: Nothing
 */
void div_op(stack_t **hd, unsigned int linenum)
{
	int nd = 0;
	stack_t *temp = NULL;

	temp = *hd;

	for (; temp != NULL ; temp = temp->next, nd++)
		;

	if (nd < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}

	if ((*hd)->n == 0)/*no division by 0*/
	{
		dprintf(2, "L%u: division by zero\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}

	temp = (*hd)->next;
	temp->n = temp->n / (*hd)->n;
	pop_op(hd, linenum);
}
/**
 * mul_op - this function is used when multiplying the
 *     second top element of the stack with the top element
 * @hd: points to the head of the list
 * @linenum: the specific line no that the error checks with
 * Description: result is stored in second top most element
 * and top element is removed
 *
 * Return: Nothing
 */

void mul_op(stack_t **hd, unsigned int linenum)
{
	int nd = 0;
	stack_t *temp;

	temp = *hd;/*now points to first node*/

	for ( ; temp != NULL ; temp = temp->next, nd++)
		;

	if (nd < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}

	temp = (*hd)->next;
	temp->n = temp->n * (*hd)->n;
	pop_op(hd, linenum);
}

