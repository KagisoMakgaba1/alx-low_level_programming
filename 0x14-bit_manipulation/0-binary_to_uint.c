#include "main.h"

/**
 * binary_to_uint - converts a binary to an unsigned int
 * @b: string containg the binary number
 *
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int dec = 0;

	if (b == NULL)
		return (0);

	for (j = 0; b[j] != '\0'; ++j)
	{
		if (b[j] != '0' && b[j] != '1')
			return (0);
		dec = 2 * dec + (b[j] - '0');
	}
	return (dec);
}
