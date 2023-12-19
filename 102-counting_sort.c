#include "sort.h"
#include <string.h>
/**
 * counting_sort - function that sorts an array of integers in
 *				ascending order using the Counting sort algorithm.
 * @array: the array of integers to be sorted.
 * @size: the size of the array.
*/
void counting_sort(int *array, size_t size)
{
	size_t i;
	int x;
	int max = array[0];
	int *counting_array, *sorted_array;

	if (array == NULL || size < 2)
		return;
	
	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	counting_array = malloc(sizeof(int) * (max + 1));
	if (!counting_array)
		return;
	memset(counting_array, 0, sizeof(int) * (max + 1));
	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(counting_array);
		return;
	}
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	for (i = 1; i < (size_t)(max + 1); i++)
		counting_array[i] += counting_array[i - 1];
	print_array(counting_array, max + 1);
	for (i = 0; i < size; i++)
	{
		x = (array[i] == 0) ? 0 : 1; 
		sorted_array[counting_array[array[i]] - x] = array[i];
		counting_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(counting_array);
	free(sorted_array);
}
