#include "monty.h"

void (*f)(stack_t **stack, unsigned int line_number);
exec_t vexec;

/**
 * free_exec - function that is used to execution members
 *
 * Return: Nothing
 */
void free_exec(void)
{
	free_dlist(vexec.head);
	free(vexec.buff);
	fclose(vexec.fd);
}

/**
 * init_exec - function used to initialize the exec_t 
 * members
 *
 * @fd: the file descriptor
 *
 * Return: Nothing
 */

void init_exec(FILE *fd)
{
	vexec.currline = 1;
	vexec.lifo = 1;
	vexec.arg = NULL;
	vexec.head = NULL;
	vexec.fd = fd;
	vexec.buff = NULL;
}

/**
 * find_file - function used to look for a file and if
 * opening it is possible
 *
 * @argc: the number of the arguments
 * @argv: the arguements themselves
 *
 * Return: the specific file
 */
FILE *find_file(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");/*read mode*/

	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
 
/**
 * main - this represents the entry point
 * of the program
 *
 * @argc: the number of arguments provided
 * @argv: the arguements themselves
 * Return: 0 if successfull
 */
int main(int argc, char *argv[])
{
	ssize_t numlines = 0;
	char *myarr[2] = {NULL, NULL};
	size_t size = 256;
	FILE *fd;


	fd = find_file(argc, argv);
	init_exec(fd);
	numlines = getline(&vexec.buff, &size, fd);
	while (numlines != -1)
	{
		myarr[0] = string_tok(vexec.buff, " \t\n");
		if (myarr[0] && myarr[0][0] != '#')
		{
			f = find_opcodes(myarr[0]);
			if (f == NULL)
			{
				dprintf(2, "L%u: ", vexec.currline);
				dprintf(2, "unknown instruction %s\n", myarr[0]);
				free_exec();
				exit(EXIT_FAILURE);
			}
			vexec.arg = string_tok(NULL, " \t\n");
			f(&vexec.head, vexec.currline);
		}
		numlines = getline(&vexec.buff, &size, fd);
		vexec.currline++;
	}

	free_exec();

	return (0);
}
