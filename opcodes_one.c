#include "monty.h"

/**
 * _pushstck - function that is used when pushing
 *            data into the stack
 * @hd: this points to the head pointer of list which points
 *        to the linked list
 * @linenum: the line number where the error should check with
 *
 * Return: Nothing
 */

void _pushstck(stack_t **hd, unsigned int linenum)
{
	int n;
	int p;

	if (vexec.arg == NULL)
	{
		dprintf(2, "L%u: ", linenum);
		dprintf(2, "usage: push integer\n");
		free_exec();
		exit(EXIT_FAILURE);
	}

	for (p = 0 ; vexec.arg[p] != '\0' ; p++)
	{
		if (!isdigit(vexec.arg[p]) && vexec.arg[p] != '-')
		{
			dprintf(2, "L%u: ", linenum);
			dprintf(2, "usage: push integer\n");
			free_exec();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vexec.arg);

	if (vexec.lifo == 1)
		add_nodebegin(hd, n);
	else
		add_node_end(hd, n);
}

/**
 * _pallstck - function which prints all the data in a stack
 *          sratting from top
 * @hd: points to the head of the list which points to
 *        the specific linked list
 * @linenum: specif line number error to reference
 *
 * Return: nothing
 */

void _pallstck(stack_t **hd, unsigned int linenum)
{
	stack_t *now_node;
	(void)linenum;

	now_node = *hd;

	while (now_node != NULL)
	{
		printf("%d\n", now_node->n); /*access member*/
		now_node = now_node->next;
	}
}

/**
 * pint_op - this function prints the value at top of
 *          specific stack
 * @hd: points to the head of list which points to the
 *     linked list itself
 * @linenum: the line number which error is to check
 *
 * Return: Nothing
 */

void pint_op(stack_t **hd, unsigned int linenum)
{
	(void)linenum;/* not to be used*/

	if (!*hd)
	{
		dprintf(2, "L%u: ", linenum);/*tostderr*/
		dprintf(2, "can't pint, stack empty\n");
		free_exec();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*hd)->n);/*what head points to*/
}

/**
 * pop_op - function used when removing the top most
 *          element in a stack
 * @hd: this points to the head which points to the
 *      linked list itself
 * @linenum: this is the line no where error is to
 *           reference
 * Return: Nothing
 */

void pop_op(stack_t **hd, unsigned int linenum)
{
	stack_t *temp;

	if (!hd || !*hd)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}
	temp = *hd;
	*hd = (*hd)->next;
	free(temp);
}

/**
 * op_swap - function used to swap the top two elements
 *           of a stack
 * @hd: used to pint to the head of the list which is a
 *      pointer to the linked list
 * @linenum: this is line mo where error is to check
 *
 * Return: void
 */

void op_swap(stack_t **hd, unsigned int linenum)
{
	stack_t *temp = NULL;
	int x = 0;

	temp = *hd;/*is now the top element*/

	for (; temp != NULL ; temp = temp->next, x++)
		;

	if (x < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", linenum);
		free_exec();
		exit(EXIT_FAILURE);
	}

	temp = *hd;
	*hd = (*hd)->next;
	temp->next = (*hd)->next;
	temp->prev = *hd;/*point back to top*/
	(*hd)->next = temp;
	(*hd)->prev = NULL;
}
