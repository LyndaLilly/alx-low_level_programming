#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * sum_listint - Traverse the linked list and add up the values
 * @head: first node in the linked list
 * Return: if the list is empty, return 0
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
