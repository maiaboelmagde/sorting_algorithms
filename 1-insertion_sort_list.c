#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Double pointer to the head of the list
 * @curr: Node to be swapped.
 * @prev_node: Previous node of the node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *curr, listint_t *prev_node)
{
	prev_node->next = curr->next;
	if (curr->next)
		curr->next->prev = prev_node;

	curr->next = prev_node;
	curr->prev = prev_node->prev;
	prev_node->prev = curr;

	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
}

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: list of integers that should be sorted.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;
	listint_t *current = *list;

	if (*list == NULL)
		return;

	for (i = current->next; i != NULL; i = i->next, current = i)
	{

		j = i->prev;

		while (j != NULL  && j->n > current->n)
		{
			swap_nodes(list, i, j);
			print_list(*list);
			j = current->prev;
		}
	}
}
