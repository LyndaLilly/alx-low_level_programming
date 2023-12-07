#include "lists.h"

/**
 * get_dnodeint_at_index - gets the node at index
 * @head: this is the head of the list
 * @index: index of the node
 * Return: node or null
 **/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int x;
	dlistint_t *res;

	x = 0;
	if (head == NULL)
	return (NULL);

	res = head;
	while (res)
	{
	if (index == x)
	return (res);
	x++;
	res = res->next;
	}
	return (NULL);
}
