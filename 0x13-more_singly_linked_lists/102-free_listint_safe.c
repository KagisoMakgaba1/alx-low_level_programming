#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @h: pointer to the first node in the list
 *
 * Return: the size of the list that was free’d
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t i = 0;
	int index;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		index = *h - (*h)->next;
		if (index > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			i++;
		}
		else
		{
			free(*h);
			*h = NULL;
			i++;
			break;
		}
	}

	 *h = NULL;

	return (i);
}
