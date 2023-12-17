#include "sort.h"
#include <stdio.h>
/**
 * swap_numbers - swap two numbers.
 * @num1: int.
 * @num2: int.
*/
void swap_numbers(int *num1, int *num2)
{
	int tmp = *num1;

	*num1 = *num2;
	*num2 = tmp;
}
/**
 * lomuto_partition - Lomuto partition scheme for quicksort.
 *
 * This function takes last element as pivot, places the pivot element at its
 * correct position in sorted array, and places all smaller (smaller than
 * pivot) to left of pivot and all greater elements to right of pivot.
 *
 * @array: The array to be partitioned.
 * @size: The array size.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The final sorted position of the chosen pivot.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap_numbers(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap_numbers(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quick_sort_Helper - Recursively sorts a subarray using the QuickSort
 *                      algorithm.
 *
 * @array: The array to be sorted.
 * @size: The array size.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray.
 */
void quick_sort_Helper(int *array, size_t size, int low, int high)
{
	int part;

	if (low < high)
	{
		part = lomuto_partition(array, size, low, high);
		quick_sort_Helper(array, size, low, part - 1);
		quick_sort_Helper(array, size, part + 1, high);
	}
}
/**
 * quick_sort - Function sorts an array of integeres using
 *              quick sort algorithm and lomuto partitioning scheme.
 * @array: the array to be sorted.
 * @size: the size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_Helper(array, size, 0, (size - 1));
}
