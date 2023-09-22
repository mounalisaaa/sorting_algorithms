#include "sort.h"

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *arr, int l, int h, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = arr[h];
	i = l - 1;
	j = l;
	while (j < h)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[h]);
	print_array(arr, size);
	return (i + 1);
}

void quick_rec(int *array, int low, int high, int size)
{
	int pivot;
	
	if (low < high)
	{
		pivot = partition(array, low, high, size);

		quick_rec(array, low, pivot - 1, size);
		quick_rec(array, pivot + 1, high, size);
	}
}

void quick_sort(int *array, size_t size)
{
	quick_rec(array, 0, size - 1, size);
}
