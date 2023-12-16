#include "sort.h"
/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 *
 * Return: 1 on success, otherwise 0.
 */
int swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	if (head == NULL || *head == NULL || *node1 == NULL ||
	node1 == NULL || node2 == NULL)
		return (0);

	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = (*node1);
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
	return (1);
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *itr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = current)
	{
		current = itr->next;
		temp = itr->prev;
		while (temp != NULL && itr->n < temp->n)
		{
			swap_nodes(list, &temp, itr);
			print_list((const listint_t *)*list);
		}
	}
}
