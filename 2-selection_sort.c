#include "sort.h"

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int *array, size_t size)
{
	size_t min;
	size_t i;
	size_t j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		min = i;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
		i++;
	}
}
