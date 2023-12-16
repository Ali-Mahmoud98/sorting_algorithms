#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	for (; current != NULL; current = current->next)
	{
		temp = current;
		for (; temp->prev != NULL && temp->n < temp->prev->n;
			temp = temp->prev)
		{
			/* Swap nodes if the current node's */
			/* value is less than the previous node's value */
			if (temp->next != NULL)
                temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            temp->next = temp->prev;
            temp->prev = temp->prev->prev;
            temp->next->prev = temp;

			/* Update the head of the list if needed */
			if (temp->prev == NULL)
                *list = temp;
			print_list(*list);
		}
		current = current->next;
	}

}
