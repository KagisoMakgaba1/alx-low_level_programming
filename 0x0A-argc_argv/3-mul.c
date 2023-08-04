#include <stdio.h>
#include <stdlib.h>

/**
*main - multiplies two numbers.
*@argc: number of command line arguments
*@argv: array containing the command line arguments
*
*Return: 0 if success, 1 otherwise
*/

int main(int argc, char *argv[])
{
	if (argc - 1 != 2)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	}
	return (0);
}
