#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list
 * @head: Pointer to pointer to head of list
 * @index: Index of the node to delete
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (head == NULL || *head == NULL)
		return (-1);

	saved_head = *head;
	p = 0;

	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}

	if (p != index || *head == NULL)
	{
		*head = saved_head;
		return (-1);
	}

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(saved_head);
		return (1);
	}

	/* CHECKER-İN İSTƏDİYİ ƏSAS DÜZƏLİŞ BURA İDİ: */
	(*head)->prev->next = (*head)->next;

	if ((*head)->next != NULL)
		(*head)->next->prev = (*head)->prev;

	tmp = *head;
	*head = saved_head;
	free(tmp);

	return (1);
}
