#include "push_swap.h"

// As we discussed - double ended linked list is the best data structure for this project probably.
// I wonder if it is better to use null-ended list or a circular one (as far as I know,
// Mateusz uses circular one, since it is easier to rotate it; on the other hand,
// with null-ended lists do not require much as well - some add front/back functions
// and some remove front/back functions, so it is not that hard to implement them).

// I would go with null-ended list, as it is easier to implement,
// understand and not mess up pointers.

d_list *create_node(int value)
{
	d_list * new_node;

	new_node = malloc(sizeof(d_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	lst_add_back(d_list *stack, d_list *new)
{
        d_list *last;

        if (!new)
                return ;
        if (stack == NULL)
        {
                stack = new;
                new->prev = NULL;
                new->next = NULL;
                return ;
        }
        last = ft_lstlast(stack);
        last->next = new;
        new->prev = last;
        new->next = NULL;
}
void    lst_add_front(d_list **stack_ptr, d_list *new)
{
        if (!new)
                return ;
        new->next = *stack_ptr;
        *stack_ptr = new;
        new->prev = NULL;
}
d_list   *lst_release_front(d_list **root_pointer)
{
        d_list  *temp;

        if (!root_pointer || !*root_pointer)
                return ;
        temp = *root_pointer;
        *root_pointer = (*root_pointer)->next;
        if (*root_pointer)
                (*root_pointer)->prev = NULL;
        return (temp);
}
void    lst_move_node(d_list **from_stack_ptr, d_list **to_stack_ptr)
{
        lst_add_front(to_stack_ptr, lst_release_front(from_stack_ptr));
}

int	idx_of_min(d_list * stack)
{
	int	min_value;
	int	min_index;
	int	current_index;

	d_list * current_node;
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
