#include "sort.h"
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

	for (int j = low; j <= high; j++) {
		if (array[j] < pivot) {
			i++;
			swap_nums(array[i], array[j]);
			print_array(array, size);
		}
	}
	swap_nums(array[i + 1], array[high]);
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
void quick_sort_Helper(int *array, size_t size ,int low, int high)
{
	int part;

	if (low < high)
	{
		part = lomuto_partition(array, size,low, high);
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
	quick_sort_Helper(array, size, 0, size - 1);
}
