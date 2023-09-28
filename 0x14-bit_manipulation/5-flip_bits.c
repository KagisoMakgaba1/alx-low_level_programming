#include "main.h"

/**
 * flip_bits - returns number of bits you would need to flip to
 * get the 2nd number front the 1st number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int count = 0;

	while (n)
	{
		if ((n & 1) != (m & 1))
			count++;
		n = n >> 1;
		m = m >> 1;
	}
	return (count);
}
