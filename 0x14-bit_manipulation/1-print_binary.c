#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 *
 * @n: number parameter
 */

void print_binary(unsigned long int n)
{
	int num = 0;
	unsigned long int curr = n;

	while (curr)
	{
		curr = curr >> 1;
		num++;
	}

	if (!num)
		putchar('0');

	while (num)
	{
		curr = n >> --num;
		if (curr & 1)
			putchar('1');
		else
			putchar('0');
	}
}
