#include "sort.h"
#include <stdio.h>
/**
 * merge - Merge two subarrays into a sorted array.
 *
 * @array: The original array containing two sorted subarrays.
 * @size: The total size of the array.
 * @left: The starting index of the left subarray.
 * @middle: The ending index of the left subarray.
 * @right: The ending index of the right subarray.
 */
void merge(int *array, int *buff, size_t left, size_t middle, size_t right)
{
    size_t i, j, k = 0;

    printf("Merging...\n[left]: ");
	print_array(&array[left], middle - left);

    printf("[right]: ");
	print_array(&array[middle], right - middle);

    for (i = left, j = middle; i < middle && j < right; k++)
		buff[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < middle; i++)
		buff[k++] = array[i];
	for (; j < right; j++)
		buff[k++] = array[j];
	for (i = left, k = 0; i < right; i++)
		array[i] = buff[k++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
/**
 * merge_sort_recursive - Recursively apply merge sort to the array.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the subarray to be sorted.
 * @right: The ending index of the subarray to be sorted.
 */
void merge_sort_recursive(int *array, int *buff, size_t left, size_t right)
{
    size_t middle;

    if (right - left > 1)
    {
        middle = left + (right - left) / 2;

        /* Recursively sort the first and second halves */
        merge_sort_recursive(array, buff, left, middle);
        merge_sort_recursive(array, buff, middle, right);

        /* Merge the sorted halves */
        merge(array, buff, left, middle, right);
    }
}
/**
 * merge_sort - function that sorts an array of integers in ascending
 *              order using the Merge sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of array.
*/
void merge_sort(int *array, size_t size)
{
    int *buff;

    if (array == NULL || size < 2)
        return;
    
    buff = malloc(sizeof(int) * size);
    if (!buff)
        return;
    merge_sort_recursive(array, buff, 0, size);
    free(buff);
}
