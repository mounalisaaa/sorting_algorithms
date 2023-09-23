#include "sort.h"

/**
 * list_len - Computes the number of elements in a linked list.
 *
 * @list: Pointer to the head of the linked list.
 *
 * Return: The number of elements in the linked list.
 */
size_t list_len(listint_t *list)
{
	size_t i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

/**
 * swap - Swaps two nodes in a doubly linked list.
 *
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 * @list: Pointer to the head of the linked list.
 *
 */

void swap(listint_t *a, listint_t *b, listint_t **list)
{
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	b->prev = a->prev;
	b->next = a;
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;
	a->prev = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker
 *                     (Bidirectional Bubble Sort) algorithm.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 *
 */
void cocktail_sort_list(listint_t **list)
{
	size_t i, j, len;
	listint_t *curr;
	int swapped;

	i = 0;
	len = list_len(*list);
	curr = *list;
	while (i < len)
	{
		j = 0;
		swapped = 0;
		while (j++ < len - i - 1)
		{
			if (curr->n > curr->next->n)
			{
				swap(curr, curr->next, list);
				print_list(*list);
				swapped = 1;
				curr = curr->prev;
			}
			curr = curr->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (j-- > i)
		{
			if (curr->n < curr->prev->n)
			{
				swap(curr->prev, curr, list);
				print_list(*list);
				swapped = 1;
				curr = curr->next;
			}
			curr = curr->prev;
		}
		if (!swapped)
			break;
		i++;
	}
}
