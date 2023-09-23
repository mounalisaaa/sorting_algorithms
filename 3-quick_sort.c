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
 * partition - Partitions an array for the Quicksort algorithm.
 *
 * @arr: Pointer to the array to be partitioned.
 * @l: The low index of the partition.
 * @h: The high index of the partition.
 * @size: Size of the array.
 *
 * Description: This function takes an array and partitions it into two
 * subarrays, with elements less than or equal to the pivot on the left side
 * and elements greater than the pivot on the right side. It uses the last
 * element as the pivot and returns the index of the pivot after partitioning.
 * Additionally, it prints the array after each partitioning step.
 * Return: The index of the pivot element in the partitioned array.
 */
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

/**
 * quick_rec - Recursively sorts an array using the Quicksort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @low: The low index of the current partition.
 * @high: The high index of the current partition.
 * @size: Size of the array.
 *
 * Description: This function recursively sorts an array using the Quicksort
 * algorithm. It selects a pivot element, partitions the array into two
 * subarrays, and recursively sorts each subarray.
 * The sorting process is done
 * in-place.
 */
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

/**
 * quick_sort - Sorts an array using the Quicksort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Quicksort algorithm. It initializes the sorting process by calling
 * the recursive `quick_rec` function.
 */
void quick_sort(int *array, size_t size)
{
	quick_rec(array, 0, size - 1, size);
}
