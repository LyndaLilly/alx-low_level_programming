#include <stdlib.h>
#include "lists.h"
/**
* list_len - this is going to return the no of elements in a linked list
* @h: This code  point to the list_t list
* Return: n
*/
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}
