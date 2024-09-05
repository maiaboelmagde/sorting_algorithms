#include "sort.h"

/**
 * partition_part -  a function that get the pivot.
 *
 * @arr: the array we should sort.
 * @low: low boundary.
 * @heigh: heigh boundary.
 * @size: number of members in that array.
 * Return: the pivot index.
 */

int partition_part(int *arr, int low, int heigh, size_t size)
{

	int i, counter = low - 1, pivot = arr[heigh];

	for (i = low; i <= heigh; i++)
	{
		if (arr[i] < pivot)
		{
			counter++;
			if (counter != i)
			{
				arr[counter] += arr[i];
				arr[i] = arr[counter] - arr[i];
				arr[counter] -= arr[i];
				print_array(arr, size);
			}
		}
	}
	if (counter + 1 != heigh)
	{
		arr[counter + 1] += arr[heigh];
		arr[heigh] = arr[counter + 1] - arr[heigh];
		arr[counter + 1] -= arr[heigh];
	}
	print_array(arr, size);
	return (counter + 1);
}

/**
 * recursive_part -  a function that perform recursive part of Quick sort.
 *
 * @arr: the array we should sort.
 * @low: low boundary.
 * @heigh: heigh boundary.
 * @size: number of members in that array.
 */

void recursive_part(int *arr, int low, int heigh, size_t size)
{
	if (low < heigh)
	{
		int pivot = partition_part(arr, low, heigh, size);

		recursive_part(arr, low, pivot - 1, size);
		recursive_part(arr, pivot + 1, heigh, size);
	}
}


/**
 * quick_sort -  a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 *
 * @array: the array we should sort.
 * @size: number of members in that array.
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	recursive_part(array, 0, size - 1, size);
}
