#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, m, index;
	int temp;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (m = i + 1; m < size; m++)
		{
			if (array[m] < array[index])
			index = m;
		}
		if (index != i)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			print_array(array, size);
		}
	}
}
