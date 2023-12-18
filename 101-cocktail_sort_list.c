#include "sort.h"
void swap_nodes2(listint_t **list, listint_t **node1, listint_t *node2);
void cocktail_sort_list(listint_t **list);
/**
 * swap_nodes2 - Swaps two nodes in a doubly linked list.
 *
 * @list: Double pointer to the head of the doubly linked list.
 * @node1: Pointer to the first node to be swapped.
 * @node2: Pointer to the second node to be swapped.
 */
void swap_nodes2(listint_t **list, listint_t **node1, listint_t *node2)
{
	listint_t *tmp = node2;
	int direction = FORWARD_SWAP;

	if (list == NULL || *list == NULL || *node1 == NULL || node2 == NULL)
		return;
	/* swap node1 and node 2 if loop goes towards head of the list. */
	if ((*node1)->prev == node2)
	{
		node2 = *node1;
		*node1 = tmp;
		direction = BACKWARD_SWAP;
	}
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = (*node1);
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;
	(*node1)->prev = node2;
	if (direction == FORWARD_SWAP)
		*node1 = node2;
}
/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers.
 *					in ascending order using the Cocktail shaker sort algorithm.
 * @list: pointer to pointer to head node in Doubly linked list.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	listint_t *helper_ptr = *list;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	end = NULL;
	while (swapped)
	{
		swapped = 0;
		for (start = helper_ptr; start != end; start = start->next)
		{
			if (!start->next)
				break;
			if (start->n > start->next->n)
			{
				swap_nodes2(list, &start, (start->next));
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (end = start->prev; end != helper_ptr; end = end->prev)
		{
			if (!end->prev)
				break;
			if (end->n < end->prev->n)
			{
				swap_nodes2(list, &end, (end->prev));
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
        helper_ptr = end->next;
		end = start->prev;
	}
}
