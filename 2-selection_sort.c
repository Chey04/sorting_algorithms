#include "sort.h"

/**
 * selection_sort - function to sort array using selection sort
 * @array: array to sort
 * @size: lenght of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, idx;

	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
				idx = j;
		}
		temp = array[idx];
		array[idx] = array[i];
		array[i] = temp;

		print_array(array, size);
	}
}
