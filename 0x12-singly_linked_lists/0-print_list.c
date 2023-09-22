#include <stdio.h>
#include "lists.h"
/**
* print_list - this is going to print all the elements
* @h: this points to the list_t list to print them
* Return: no of node that will be printed
*/
size_t print_list(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		a++;
	}
	return (a);
}
