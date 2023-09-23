#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

void shaker(int *arr, int size)
{
	int i;
	int j;
	int swapped;

	i = 0;
	while (i < size)
	{
		swapped = 0;
		j = i;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				print_array(arr, size);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (j > i)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(&arr[j], &arr[j - 1]);
				print_array(arr, size);
				swapped = 1;
			}
			j--;
		}
		if (!swapped)
			break;
		i++;
	}
}

int main(void)
{
	int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int  n = sizeof(arr) / sizeof(arr[0]);
	print_array(arr, n);
	printf("\n");
	shaker(arr, n);
	printf("\n");
	print_array(arr, n);
	return (0);
}
