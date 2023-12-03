#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Return: Always 0
 */

int main(void)
{
	char *lineptr = NULL;
	size_t len = 0;
	ssize_t nRead;

	while (1)
	{
		printf("$ ");

		nRead = getline(&lineptr, &len, stdin);

		if (nRead == -1 || nRead == EOF)
		{
			free(lineptr);
			break;
		}

		printf("%s", lineptr);
	}
	return (0);
}
