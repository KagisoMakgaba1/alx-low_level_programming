#include <stdlib.h>
#include <stdio.h>

/**
*is_digit - checks if string contains digits
*@str: source string
*Return: 1 if success, 0 otherwise
*/

int is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/**
* main - multiply 2 numbers as arguments
* @argc: number of arguments
* @argv: argument vector
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	unsigned long int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	num1 = strtoull(argv[1], NULL, 10);
	num2 = strtoull(argv[2], NULL, 10);
	result = num1 * num2;

	printf("%lu\n", result);

	return (0);
}
