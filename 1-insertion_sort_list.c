#include "sort.h"

/**
 * insertion_sort_list - sorts a list of integers in ascending order
 * @list: list to be sorted
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sort = NULL, *current = *list, *tmp, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (current != NULL)
	{
		next = current->next;
		if (sort == NULL || sort->n >= current->n)
		{
			current->next = sort;
			current->prev = NULL;
			if (sort != NULL)
				sort->prev = current;
			sort = current;
		}
		else
		{
			tmp = sort;
			while (tmp->next != NULL && tmp->next->n < current->n)
				tmp = tmp->next;
			current->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = current;
			tmp->next = current;
			current->prev = tmp;
		}
		print_list(sort);
		current = next;
	}
	*list = sort;
}
