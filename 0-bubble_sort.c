#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Description: This function takes two integer pointers and swaps the values
 * of the integers they point to.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers using the Bubble Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Bubble Sort algorithm. It iterates through the array, comparing
 * adjacent elements, and swaps them if they are in the wrong order.
 * This process
 * is repeated until the entire array is sorted.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int swapped;

	i = 0;
	while (i < size)
	{
		j = 0;
		swapped = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break;
		i++;
	}
}
