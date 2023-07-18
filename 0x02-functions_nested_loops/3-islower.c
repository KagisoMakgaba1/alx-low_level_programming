#include "main.h"
/**
*_islower - checks for lowercase character
*@c: The characyter to be checked
*Return: 1 if c is lowercase, 0 otherwise
*/
int_islower(int c)
{
	for (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

