#include "monty.h"
#include <stdio.h>
/**
 * _modulus - this function computes the remainder of the
 * division of the sectop element of the stack
 *     by the top element
 * @hd: this points to the head of the linked list
 *
 * @linenum: this is the line number the error references
 *
 * Return: Nothing
 */

void _modulus(stack_t **hd, unsigned int linenum)
{
	stack_t *temp = NULL;
	int nd = 0;

	temp = *hd;

	for ( ; temp != NULL ; temp = temp->next, nd++)
		;

	if (nd < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}

	if ((*hd)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}

	temp = (*hd)->next;
	temp->n = temp->n % (*hd)->n;
	pop_op(hd, linenum);
}

/**
 * _printch - function that prints the char
 * of the first element
 *
 * @hd: points to the head of the linked list
 * @linenum: the line number the error uses to reference
 *
 * Return: Nothing
 */
void _printch(stack_t **hd, unsigned int linenum)
{
	if (!hd || !*hd)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}
	if ((*hd)->n < 0 || (*hd)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*hd)->n);
}

/**
 * _pstr - function used to print the string that starts
 *         at the top of the stack
 * @hd: points to the head of the linked list
 * @linenum: means the line number where the error
 *           mess references
 * Return: voud
 */

void _pstr(stack_t **hd, unsigned int linenum)
{
	stack_t *temp;
	(void)linenum;

	temp = *hd;/*points to first node*/

	while (temp && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
