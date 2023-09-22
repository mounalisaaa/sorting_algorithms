#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0;
	unsigned int ssize = size;
	int temp;

	while (i < ssize - 1)
	{
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
			i++;
		}
		i = 0;
		ssize--;
	}
}