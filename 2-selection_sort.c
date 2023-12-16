#include "sort.h"
void swap_nums(int *num1, int *num2)
{
	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;
}

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 *
 * @array: array to be sorted.
 * @size: size of array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap_nums(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
