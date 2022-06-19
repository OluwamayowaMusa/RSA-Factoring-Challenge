#include <stdio.h>
#include <stdlib.h>

/**
 * main - Factorise number
 * @argc: Argument count
 * @argv: Argument Vector
 *
 * Return: Always  zero
 */
int main(int argc, char *argv[])
{
	FILE *fp; /* File pointer */
	char *line = NULL;
	size_t num =  0;
	unsigned long long int val, i = 2;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &num, fp) != -1)
	{
		val = (unsigned long long int)atoll(line);
		while (val % i != 0)
			i++;
		printf("%lld=%lld*%lld\n", val, val / i, i);
		i = 2;
	}
	return (0);
}
