#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked
 * list, and returns the head node's data (n).
 * @head: pointer to the first element of the list
 *
 * Return: the head node’s data (n), or 0 if it's empty
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int k;

	if (*head == NULL)
		return (0);

	k = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (k);
}
