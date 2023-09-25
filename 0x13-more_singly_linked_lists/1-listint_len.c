#include <stddef.h>
#include "lists.h"
/**
 * listint_len - Definition of the listint_t structure
 * @h: link list of type to reverse
 * Return: nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
