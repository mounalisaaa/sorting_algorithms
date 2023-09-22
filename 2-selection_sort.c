#include "sort.h"

void selection_sort(int *array, size_t size)
{
	unsigned int i = 0;
	unsigned int j, min;
	int temp;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while(j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		if (i != min)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}		
		i++;
	}
}