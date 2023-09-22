#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;
	listint_t *tp;
	listint_t *temp;

	while(curr)
	{
		tp = curr;
		temp = tp ->prev;
		while(temp && (tp->n < temp->n))
		{
			temp->next = tp->next;
			if (tp->next)
				tp->next->prev = temp;
			tp->prev = temp->prev;
			tp->next = temp;
			if (temp->prev)
				temp->prev->next = tp;
			else
				*list = tp;
			temp ->prev = tp;
			print_list(*list);
			temp = tp->prev;
		}
		curr = curr->next;
	}
}