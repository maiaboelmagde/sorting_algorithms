#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: list of integers that should be sorted.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *curr_node, *prev_node;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	curr = (*list)->next;

	while (curr)
	{
		curr_node = curr;
		while (curr_node->prev && curr_node->prev->n > curr_node->n)
		{
			prev_node = curr_node->prev;

			if (curr_node->next)
			{
				curr_node->next->prev = prev_node;
			}
			if (prev_node->prev)
			{
				prev_node->prev->next = curr_node;
			} else
			{
				*list = curr_node;
			}

			prev_node->next = curr_node->next;
			curr_node->prev = prev_node->prev;
			prev_node->prev = curr_node;
			curr_node->next = prev_node;

			print_list(*list);
		}
		curr = curr->next;
	}
}
