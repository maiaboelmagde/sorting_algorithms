#include "sort.h"

int partition_part(int *arr, int low, int heigh, size_t size)
{
    int i;
    int pivot = heigh;
    for (i = low; i < heigh; i++)
    {
        if (arr[i] > arr[pivot])
        {
            arr[i] += arr[pivot];
            arr[pivot] = arr[i] - arr[pivot];
            arr[i] -= arr[pivot];

            print_array(arr, size);
            pivot = i;
            break;
        }
        
    }
    return pivot;
    
}

void recursive_part(int *arr, int low, int heigh, size_t size)
{
    if (low < heigh)
    {
        int pivot = partition_part(arr, low, heigh, size);
        recursive_part(arr, low, pivot - 1, size);
        recursive_part(arr, pivot+1, heigh, size);
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
	if (!array)
    {
        return;
    }

    recursive_part(array, 0, size - 1, size);
    
}