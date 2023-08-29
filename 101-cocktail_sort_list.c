#include "sort.h"

void swap_node(listint_t *a, listint_t **b, listint_t **list);

/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to the doubly linked list
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *new = NULL, *main = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swap)
	{
		swap = 0;
		for (; main->next != new; main = main->next)
		{
			if (main->n > main->next->n)
			{
				swap_node(main, &(main->next), list);
				swap = 1;
				print_list(*list);
			}
		}
		if (!swap)
			break;
		swap = 0;
		new = (*list)->prev;
		for (main = new; main->prev != NULL; main = main->prev)
		{
			if (main->n < main->prev->n)
			{
				swap_node(main->prev, &main, list);
				swap = 1;
				print_list(*list);
			}
		}
	}
}

/**
 * swap_node - swaps two nodes in the list
 * @a: node to be swapped
 * @b: node to be swapped
 * @list: pointer to the doubly linked list
 */
void swap_node(listint_t *a, listint_t **b, listint_t **list)
{
	if (a->prev)
		a->prev->next = *b;
	else
		*list = *b;
	if ((*b)->next)
		(*b)->next->prev = a;
	a->next = (*b)->next;
	(*b)->prev = a;
	(*b)->next = a;
}
