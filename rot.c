#include "monty.h"

/**
 * rot_top - function used to rotate the stack
 * the top becomes bottom and second top is first
 *
 * @hd: point to the head of the linked list
 * @linenum: the line number the error is to
 *           check with
 * Return: Nothing
 */
void rot_top(stack_t **hd, unsigned int linenum)
{
	stack_t *temp1 = NULL;
	stack_t *temp2 = NULL;
	(void)linenum;

	if (!*hd)
	{
		return;
	}

	if ((*hd)->next == NULL)
		return;

	temp1 = (*hd)->next;
	temp2 = *hd;

	for ( ; temp2->next != NULL ; temp2 = temp2->next)
		;

	temp1->prev = NULL;
	temp2->next = *hd;
	(*hd)->next = NULL;
	(*hd)->prev = temp2;
	*hd = temp1;
}
/**
 * rot_rev - this function makes the last element of stack
 *           to be first element
 * @hd: points to the head of the list
 * @linenum: the line mo the error mess checks with
 *
 * Return: Nothing
 */

void rot_rev(stack_t **hd, unsigned int linenum)
{
	stack_t *tmp = NULL;
	(void)linenum;

	if (!*hd)
	{
		return;
	}

	if ((*hd)->next == NULL)
		return;

	tmp = *hd;/*to first node*/

	for ( ; tmp->next != NULL ; tmp = tmp->next)
		;

	tmp->prev->next = NULL;
	tmp->next = *hd;
	tmp->prev = NULL;
	(*hd)->prev = tmp;
	*hd = tmp;
}

