#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, m;
	int temp;

	if (array == NULL || size <= 1)
	return;
	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];

			for (m = i; m >= interval && array[m - interval] > temp; m -= interval)
			{
				array[m] = array[m - interval];
			}
			array[m] = temp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
    }
}
