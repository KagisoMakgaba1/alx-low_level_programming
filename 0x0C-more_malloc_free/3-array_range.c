#include <stdlib.h>
#include "main.h"

/**
*array_range - creates an array of integers.
*@min: minimum number
*@max: maximum number
*
*Return: pointer to address of new memory
*/

int *array_range(int min, int max)
{
	int *ptr;
	int i, j = 0;

	if (min > max)
		return (NULL);

	ptr = malloc(sizeof(ptr) * ((max - min) + 1));

	if (ptr != NULL)
	{
		for (i = min; i <= max; i++)
		{
			ptr[j] = i;
			j++;
		}
		return (ptr);
	}
	else
		return (NULL);
}
