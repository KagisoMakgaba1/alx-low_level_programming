#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* is_positive_integer - checks if a string is a positive integer
* @str: input string
* Return: 1 if positive integer, 0 otherwise
*/

int is_positive_integer(char *str)
{
	if (*str == '\0')
	{
		return (0);
	}

	while (*str != '\0')
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
* multiply_strings - multiplies two strings representing positive integers
* @str1: first input string
* @str2: second input string
* @result: buffer to store the result
* @result_size: size of the result buffer
*/

void multiply_strings(char *str1, char *str2, char *result, size_t result_size)
{
	int i, j;
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);

	memset(result, '0', result_size);

	for (i = len2 - 1; i >= 0; i--)
	{
		int carry = 0;

		for (j = len1 - 1; j >= 0; j--)
		{
			int product = (str1[j] - '0') * (str2[i] - '0') + (result[i + j + 1] - '0')
				+ carry;

			carry = product / 10;

			result[i + j + 1] = (product % 10) + '0';
		}

		result[i] = carry + '0';
	}
}

/**
*main - main function
*@argc: argument count
*@argv: argument vector
*Return: 0 on success
*/

int main(int argc, char *argv[])
{
	size_t result_size;
	char *result, *trimmed_result, *num1 = argv[1], *num2 = argv[2];

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (!is_positive_integer(argv[1]) || !is_positive_integer(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	result_size = strlen(num1) + strlen(num2) + 1;
	result = malloc(result_size);

	if (result == NULL)
	{
		printf("Error\n");
		return (98);
	}

	multiply_strings(num1, num2, result, result_size);

	trimmed_result = result;

	while (*trimmed_result == '0' && *(trimmed_result + 1) != '\0')
	{
		trimmed_result++;
	}

	printf("%s\n", trimmed_result);

	free(result);

	return (0);
}
