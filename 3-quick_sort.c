#include "sort.h"

int lomuto_partition(int *array, int down, int up, size_t size);
void quick_sort_exec(int *array, int down, int up, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the sorted array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL  || size <= 1)
		return;
	quick_sort_exec(array, 0, size - 1, size);
}

/**
 * quick_sort_exec - Recursive function that performs quick sort
 * @array: array to be sorted
 * @down: lowest partiton index
 * @up: highest partition index
 * @size: size of the array
 */
void quick_sort_exec(int *array, int down, int up, size_t size)
{
	int turn;

	if (down < up)
	{
		turn = lomuto_partition(array, down, up, size);
		quick_sort_exec(array, down, turn - 1, size);
		quick_sort_exec(array, turn + 1, up, size);
	}
}

/**
 * lomuto_partition -  implement the Lomuto partition scheme
 * @array: array to be sorted
 * @down: lowest partition index
 * @up: highest partition index
 * @size of the array
 * Return: indexof the sorted partition
 */
int lomuto_partition(int *array, int down, int up, size_t size)
{
	int i = down - 1, m, temp, turn = array[up];

	for (m = down; m <= up - 1; m++)
	{
		if (array[m] <= turn)
		{
			i++;
			if (i != m)
			{
				temp = array[i];
				array[i] = array[m];
				array[m] = temp;
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != up)
	{
		temp = array[i + 1];
		array[i + 1] = array[up];
		array[up] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
