#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void fact(long int no);

/**
 * main - Factorize numbers as possible into a product of two smaller numbers
 * @ac: Argument Counts
 * @av: Argument Vectors
 *
 * Return: 0 - ALWAYS SUCCESS
 */

int main(int ac, char **av)
{
	/*clock_t start, end;*/

	FILE *ptr;
	char ch;
	char buf[100];
	int i = 0;
	long int new;

	/*start = clock();*/

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	ptr = fopen(av[1], "r");
	if (ptr == NULL)
	{
		dprintf(STDERR_FILENO, "Failed to Open %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	do {
		ch = fgetc(ptr);

		if (ch)
		{
			buf[i] = ch;
		}
		if (ch == '\n')
		{
			buf[i] = '\0';
			new = atol(buf);
			fact(new);
			i = 0;
			continue;
		}

		i++;
	} while (ch != EOF);

	/*
	 * end = clock();
	*cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
	*/

	return (0);
}

/**
 * fact - Find and Print the Factors of a Number
 * @no: Number to be factorized
 *
 * Return: void
 */

void fact(long int no)
{
	int i = 2;
	long int num;

	for (; i < no; i++)
	{
		num = (long int)(no / i);
		if (num * i ==  no)
		{
			printf("%ld = %ld * %d\n", no, num, i);
			break;
		}
	}
}
