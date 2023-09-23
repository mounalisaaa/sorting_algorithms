#include "sort.h"

/**
 * _max - Find the maximum value in an array of integers.
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 * Return: The maximum value found in the array.
 */
int _max(int *array, size_t size)
{
	size_t i;
	int  max;

	max = array[0];
	i = 1;
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

/**
 * counting_sort - Sorts an array of integers using
 * the Counting Sort algorithm.
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 */
void counting_sort(int *array, size_t size)
{
		int i;
		int *count_arr, *out_arr, max;

		if (!array || size < 2)
			return;
		max = _max(array, size);
		count_arr = (int *)malloc(sizeof(int) * (max + 1));
		if (!count_arr)
			return;
		out_arr = (int *)malloc(sizeof(int) * size);
		if (!out_arr)
		{
			free(count_arr);
			return;
		}
		i = 0;
		while (i <= max)
			count_arr[i++] = 0;
		i = 0;
		while (i < (int)size)
		{
			count_arr[array[i]]++;
			i++;
		}
		i = 1;
		while ((int)i <= max)
		{
			count_arr[i] += count_arr[i - 1];
			i++;
		}
		print_array(count_arr, max + 1);
		i = 0;
		while (i < (int)size)
		{
			out_arr[count_arr[array[i] - 1]] = array[i];
			count_arr[array[i]]--;
			i++;
		}
		i = 0;
		while (i < (int)size)
		{
			array[i] = out_arr[i];
			i++;
		}
		free(count_arr);
		free(out_arr);
}
