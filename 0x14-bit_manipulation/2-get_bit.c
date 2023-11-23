#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: decimal number
 * @index: index starting from 0 of the bit you want to get
 *
 * Return: value of a but at index or -1 on error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 32)
		return (-1);

	return ((n >> index) & 1);
}
