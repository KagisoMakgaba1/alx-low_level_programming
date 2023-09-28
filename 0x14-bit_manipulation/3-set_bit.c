#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: decimal number
 * @index: index starting from 0 of the bit you want to get.
 *
 * Return: 1 if set, or -1 on error.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 32)
		return (-1);
	*n = *n | (1 << index);

	return (1);
}
