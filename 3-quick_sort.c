#include "sort.h"

void quick_sort(int *array, size_t size)
{
	unsigned int j = 0;
	unsigned int i = 0;
	int pivot = array[size - 1];
	int temp;

	if (size < 2)
		return;
	while (j < size)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

			}
		}
		j++;
	}
	if (i < size - 1)
	{
		temp = array[i];
		array[i] = array[size - 1];
		array[size - 1] = temp;
		print_array(array, size);
	}
	if (i > 0)
		quick_sort(array, i - 1);
	if (i < size - 1)
		quick_sort(array + i + 1, size - i - 1);
}