#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to the first element of the list
 *
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *nextNode;

	while (*head != NULL)
	{
		nextNode = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = nextNode;
	}

	*head = prev;

	return (*head);
}
