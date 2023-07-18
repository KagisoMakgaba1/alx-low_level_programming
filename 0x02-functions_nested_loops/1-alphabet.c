#include "main.h"
/**
 * main - prints the alphabet, in lowercase
 *followed by a new line
 * Return: Nothing.
 */
void print_alphabet(void)
{
	int l;

	for (l = 'a'; l <= 'z'; l++)
	{
		_putchar(l);
	}
	_putchar('\n');
}
