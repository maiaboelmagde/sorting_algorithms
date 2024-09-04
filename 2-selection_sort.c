#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: the array we should sort
 * @size: number of elements in that array
 * Return: (void)
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_num;

	if (!array)
	{
		return;
	}


	for (i = 0; i < size; i++)
	{
		min_num = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min_num] > array[j])
			{
				min_num = j;
			}
		}
		if (min_num != i)
		{
			array[i] += array[min_num];
			array[min_num] = array[i] - array[min_num];
			array[i] -= array[min_num];
			print_array(array, size);
		}
	}
}
