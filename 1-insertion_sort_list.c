#include "sort.h"

void swap(listint_t **list, listint_t *a, listint_t *b)
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

void insertion_sort_list(listint_t **list)
{
	listint_t *i;
	listint_t *j;
	listint_t *prev;
	
	if (!list || !(*list) || !(*list)->next)
		return ;
	i = (*list)->next;
	while (i)
	{
		j = i;
		prev = j->prev;
		while (prev != NULL && prev->n > j->n)
		{
			swap(list, prev, j);
			prev = j->prev;
			print_list(*list);
		}
		i = i->next;
	}
}
