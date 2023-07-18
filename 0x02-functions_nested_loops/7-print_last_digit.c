#include "main.h"
/**
*print_last_digit - prints the last digit of a number
*@l: input number as an integer
*Return: the last digit
*/
int print_last_digit(int l)
{
	int l;

	l = n % 10;
	if (l < 0)
		l = l * -1;
	_putchar(l + '0');
	return (l);
}
