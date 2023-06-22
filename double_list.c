#include "monty.h"

/**
 * add_nodebegin - this function adds a node at the
 *      beginning od a doubly linked list
 * @hd: points to the head of the list
 * @n: the node being added
 *
 * Return: list with added node
 */
stack_t *add_nodebegin(stack_t **hd, const int n)
{
	stack_t *cpy;

	if (!hd)
	{
		return (NULL);
	}
	cpy = malloc(sizeof(stack_t));
	if (cpy == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_exec();
		exit(EXIT_FAILURE);
	}
	cpy->n = n;

	if (!*hd)
	{
		cpy->next = *hd;
		cpy->prev = NULL;
		*hd = cpy;
		return (*hd);
	}
	(*hd)->prev = cpy;
	cpy->next = (*hd);
	cpy->prev = NULL;
	*hd = cpy;

	return (*hd);
}

/**
 * add_node_end - function which adds node to the end of a
 * doubly linked list
 *
 * @hd: points to the first node in the list
 * @n: the node to be added
 *
 * Return: the doubly list with node at end
 */
stack_t *add_node_end(stack_t **hd, const int n)
{
	stack_t *cpy;
	stack_t *tmp;

	if (!hd)
	{
		return (NULL);
	}
	tmp = malloc(sizeof(stack_t));
	if (tmp == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_exec();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;
	if (!*hd)
	{
		tmp->next = *hd;
		tmp->prev = NULL;
		*hd = tmp;
		return (*hd);
	}
	cpy = *hd;
	while (cpy->next)
		cpy = cpy->next;

	tmp->next = cpy->next;
	tmp->prev = cpy;
	cpy->next = tmp;
	return (cpy->next);
}

/**
 * free_dlist - function which frees the doubly linked list
 *
 * @hd: points to the head of the list
 *
 * Return: Nothing
 */
void free_dlist(stack_t *hd)
{
	stack_t *curr;

	while ((curr = hd) != NULL)
	{
		hd = hd->next;
		free(curr);
	}
}
