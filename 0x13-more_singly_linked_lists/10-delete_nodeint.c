#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a
 * listint_t linked list
 * @head: pointer to the first element of the list
 * @index: the index of the node that should be deleted.
 * index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *curr_node = *head;
	unsigned int j;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (j = 0; j < index - 1; j++)
	{
		if (curr_node == NULL || curr_node->next == NULL)
		{
			return (-1);
		}
		curr_node = curr_node->next;
	}

	temp = curr_node->next;
	curr_node->next = temp->next;
	free(temp);
	return (1);
}
