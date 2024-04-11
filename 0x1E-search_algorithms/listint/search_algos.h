#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - this is a linked list
 * @n: this is the integer
 * @index: this is the index
 * @next: this is the next node
 * Description: singly linked list is for Holberton program
 */
typedef struct listint_s
{
        int n;
        size_t index;
        struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s -this linked list
 * @n: this is an intger
 * @index: this is the index
 * @next: this is the next node
 * @express: this is the express node
 * Description: singly linked list is for Holberton program
 */
typedef struct skiplist_s
{
        int n;
        size_t index;
        struct skiplist_s *next;
        struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
