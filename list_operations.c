#include "push_swap.h"

// As we discussed - double ended linked list is the best data structure for this project probably.
// I wonder if it is better to use null-ended list or a circular one (as far as I know,
// Mateusz uses circular one, since it is easier to rotate it; on the other hand,
// with null-ended lists do not require much as well - some add front/back functions
// and some remove front/back functions, so it is not that hard to implement them).

// I would go with null-ended list, as it is easier to implement,
// understand and not mess up pointers.

t_dlist	*create_node(int value)
{
	t_dlist	*new_node;

	new_node = malloc(sizeof(t_dlist));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	lst_add_back(t_state *state, t_dlist *to_add, t_dlist **head, t_dlist **tail)
{
	t_dlist	*last;

        if (!head || !tail || !to_add)
		return ;
        if (!(*head))
        {
                lst_add_front(state, to_add, head, tail);
                return  ;
        }
        else 
        {
                (*tail)->next = to_add;
                to_add->prev= *tail;
                to_add->next = NULL;
                (*tail)->next = to_add;
        }
}

void	lst_add_front(t_state *state, t_dlist *to_add, t_dlist **head, t_dlist **tail)
{
	t_dlist	*tmp;

	if (!head || !tail || !to_add)
		return ;
	if (!(*head))
	{
		to_add->prev = NULL;
		to_add->next = NULL;
		*head = to_add;
		*tail = to_add;
		return ;
	}
	else
	{
		to_add->next = *head;
		to_add->prev = NULL;
		*head = to_add;
	}
}

t_dlist	*lst_release_front(t_state *state, t_dlist **head, t_dlist **tail)
{
	t_dlist	*temp;

        if (!head || !tail || !(*head))
                return (NULL);
        if (*head == *tail)
        {
                temp = *head;
                *head = NULL;
                *tail = NULL;
                return (temp);
        }
        temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        return (temp);
}

// release_back neeeded - same as above but for back 
t_dlist	*lst_release_back(t_state *state, t_dlist **head, t_dlist **tail)
{
	t_dlist	*temp;

        if (!head || !tail || !(*tail))
                return (NULL);
        if (*head == *tail)
        {
                temp = *tail;
                *head = NULL;
                *tail = NULL;
                return (temp);
        }
        temp = *tail;
        *tail = (*tail)->next;
        (*tail)->next = NULL;
        return (temp);
}
// swap_firsts needed - swaps 2 first elements in stacks.

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
