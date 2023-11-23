#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 - if endian, 1 - if little endian
 *
 * Description: In big endian format the most significant byte is
 * stored first, thus gets stored at the smallest address byte,
 * while in little endian format the least significant byte
 * is stored first.
 *
 */

int get_endianness(void)
{
	unsigned int k = 1;
	char *p = (char *) &k;

	return (*p);
}
