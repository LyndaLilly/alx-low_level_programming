#include "lists.h"
/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointd to head element
 * Return: 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data;

	if (!head || !*head)
		return (0);
	data = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (data);
}
