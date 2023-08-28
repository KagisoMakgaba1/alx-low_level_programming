#include "lists.h"

/**
 * get_nodeint_at_index -  returns the nth node of a listint_t linked list
 * @head: pointer to the first element of the list
 * @index: the index of the node, starting at 0
 *
 * Return: pointer to node, or NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int d = 0;

	if (head == NULL)
		return (NULL);

	for (; d < index; d++)
	{
		head = head->next;

		if (head == NULL)
			return (NULL);
	}
	return (head);
}
