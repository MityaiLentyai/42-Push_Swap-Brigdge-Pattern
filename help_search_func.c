#include "push_swap.h"

int	check_if_swap(t_dlist *head)
{
	if (!head || !head->next)
		return (0);
	if (head->value > head->next->value)
		return (1);
	return (0);
}

size_t	list_size(t_dlist *head)
{
	size_t	size;

	size = 0;
	while (!head)
	{
		head = head->next;
		size++;
	}
	return (size);
}
