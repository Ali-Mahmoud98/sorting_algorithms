#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm.
 *
 * @array: pointer to array of integers.
 * @size: size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = 1;
				array[j] = array[j] ^ array[j + 1];
				array[j + 1] = array[j] ^ array[j + 1];
				array[j] = array[j] ^ array[j + 1];
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
