#include <stdio.h>
/**
*main - computes and prints the sum of all multiples of 3 and 5
*below 1024 (excluded)
*followed by a new line
*Return: always 0
*/
int main(void)
{
	int i, res;

	for (i = 0; i < 1024; i++)
		if (i % 3 == 0 || i % 5 == 0)
			res += i;
	printf("%d\n", res);
	return (0);
}
