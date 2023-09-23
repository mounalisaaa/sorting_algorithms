#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *               using the Shell Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 */
void shell_sort(int *array, size_t size)
{
	int gap;
	int i;
	int j;
	int temp;

	gap = 1;
	while (gap < (int)size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		i = gap;
		while (i < (int)size)
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
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
