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
int	idx_of_min(t_dlist *stack)
{
	int		min_value;
	int		min_index;
	int		current_index;
	t_dlist	*current_node;

	if (!stack)
		return (-1);
	min_value = stack->value;
	min_index = 0;
	current_index = 0;
	current_node = stack;
	while (current_node)
	{
		if (current_node->value < min_value)
		{
			min_value = current_node->value;
			min_index = current_index;
		}
		current_node = current_node->next;
		current_index++;
	}
	return (min_index);
}
