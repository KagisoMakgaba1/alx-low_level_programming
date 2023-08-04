#include <stdio.h>

/**
*main - prints name of the progman.
*@argc: number of command lines.
*@argv: an array containing the program arguments
*
*Return: Always 0
*/
int main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("%s\n", argv[0]);
	}
	return (0);
}
