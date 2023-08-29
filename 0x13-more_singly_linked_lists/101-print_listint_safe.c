#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the first element of the list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;
	size_t n = 0;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		n++;
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			printf("[%p] %d\n", (void *)fast->next, fast->next->n);
			printf("-> [%p] %d\n", (void *)fast->next->next, fast->next->next->n);
			exit(98);
		}
	}

	while (slow != NULL)
	{
		printf("]%p] %d\n", (void *)slow, slow->n);
		n++;
		slow = slow->next;
	}
	return (n);
}
