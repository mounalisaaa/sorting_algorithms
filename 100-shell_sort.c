#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t i;
	size_t j;
	int temp;

	gap = 1;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
			i++;
		}
		gap /= 3;
		print_array(array, size);
	}
}
