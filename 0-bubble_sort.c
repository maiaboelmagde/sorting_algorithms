#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: Our array
 * @size: array size
 *
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (!array)
		return;

	for (i = 0; i < size - 1 ; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
		if (swapped == false)
		{
			break;
		}

	}
}
