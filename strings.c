#include "monty.h"

/**
 * get_ch - function which finds a char in
 *              a given string
 * @str: the string to search for char in
 * @c: the char to be found in str
 *
 * Return: 1 if it is successful, otherwise 0
 */

int get_ch(char *str, char c)
{
	int currline = 0;

	while (str[currline] != '\0')
	{
		if (str[currline] == c)
		{
			break;
		}
		currline++;
	}
	if (str[currline] == c)
	{
		return (1);
	}
	else
		return (0);
}
/**
 * string_tok - function which tokenizes str depending
 * on the delimeter used
 *
 * @st: the string to be tokenized
 * @d: the delimeter used
 *
 * Return: the first token
 */
char *string_tok(char *st, char *d)
{
	int x = 0;
	int t = 0;
	static char *lastpos;

	if (st == NULL)
	{
		st = lastpos;
	}
	while (st[x] != '\0')
	{
		if (get_ch(d, st[x]) == 0 && st[x + 1] == '\0')
		{
			lastpos = st + x + 1;
			*lastpos = '\0';
			st = st + t;
			return (st);
		}
		else if (get_ch(d, st[x]) == 0 && get_ch(d, st[x + 1]) == 0)
			x++;
		else if (get_ch(d, st[x]) == 0 && get_ch(d, st[x + 1]) == 1)
		{
			lastpos = st + x + 1;
			*lastpos = '\0';
			lastpos++;
			st = st + t;
			return (st);
		}
		else if (get_ch(d, st[x]) == 1)
		{
			t++;
			x++;
		}
	}
	return (NULL);
}

/**
 * _strcmp_ - this function is used to compare two strings
 *
 * @st1: the string to be compared
 * @st2: the second str to compare
 *
 * Return: 0 if they are same m otherwise another value
 */
int _strcmp_(char *st1, char *st2)
{
	int p;

	for (p = 0 ; st1[p] == st2[p] && st1[p] ; p++)
		;
	if (st1[p] > st2[p])
	{
		return (1);
	}
	if (st1[p] < st2[p])
	{
		return (-1);
	}
	return (0);

}
