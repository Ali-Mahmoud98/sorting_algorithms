#include "sort.h"
/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *itr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = itr->next)
	{
		temp = itr->prev;
		for (; temp != NULL && temp->n > itr->n;
			temp = temp->prev)
		{
			swap_nodes(&list, &temp, itr);
			print_list((const listint_t *)*list);
		}
	}
}
