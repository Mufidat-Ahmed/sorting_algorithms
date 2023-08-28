#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * *array: array to be sorted
 * size: number of element in the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, m;
	int swap = 0, temp;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (m = 0; m < size - i - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				temp = array[m];
				array[m] = array[m + 1];
				array[m + 1] = temp;

				swap = 1;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
