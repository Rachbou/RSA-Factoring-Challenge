#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

/**
 * main - main function
 *
 * Return: void
 */
void main(int argc, char *argv[])
{
	FILE *filename;
	size_t count;
	ssize_t line;
	char *buffer = NULL;
	uint64_t number, n;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	filename = fopen(argv[1], "r");
	if (filename == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while((line = getline(&buffer, &count, filename)) != -1)
	{
		number = atoi(buffer);
		printf("%"PRIu64"\n", number);
		for (n = 2; n < number; n++)
		{
			if (number % n == 0)
			{
				printf("%"PRIu64"=%"PRIu64"*%"PRIu64"\n",number,number/n,n);
				break;
			}
		}
	}
}
