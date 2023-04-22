#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme.
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	int temp, pivot;
	size_t i, j;

	/* Base case: If size is 1 or less, array is sorted */
	if (size <= 1)
		return;

	/* Initialize pivot index to last element of array */
	pivot = array[size - 1];
	i = 0;

	/* Iterate over array from start to pivot index */
	for (j = 0; j < size - 1; j++)
	{
		/* If current element is less than or equal to pivot, swap it with i-th element */
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			if (i - 1 != j)
				print_array(array, size);
		}
	}

	/* Swap pivot element with i-th element to put pivot in correct place */
	temp = array[i];
	array[i] = array[size - 1];
	array[size - 1] = temp;
	if (i != size - 1)
		print_array(array, size);

	/* Recursive calls to sort left and right partitions */
	quick_sort(array, i);
	quick_sort(&array[i + 1], size - i - 1);
}

