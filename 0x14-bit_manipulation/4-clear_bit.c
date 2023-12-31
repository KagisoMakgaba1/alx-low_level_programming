#include "main.h"

/**
 * clear_bit - find the value of a bit to 0 at a given index
 * @n: decimal number
 * @index: index starting from 0 of the bit you want to get
 *
 * Return: 1 if it worked, or -1 if an error occured
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 32)
		return (-1);

	*n = *n & (~(1 << index));

	return (1);
}
