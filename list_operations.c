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

void	lst_add_back(t_dlist *to_add, t_dlist **head, t_dlist **tail)
{
	if (!head || !to_add)
		return ;
	if (!*head)
		lst_add_front(to_add, head, tail);
	else
	{
		(*tail)->next = to_add;
		to_add->prev= *tail;
		to_add->next = NULL;
		*tail = to_add;
	}
}

void	lst_add_front(t_dlist *to_add, t_dlist **head, t_dlist **tail)
{

	if (!head || !to_add)
		return ;
	if (!*head)
	{
		to_add->prev = NULL;
		to_add->next = NULL;
		*head = to_add;
		*tail = to_add;
	}
	else
	{
		(*head)->prev = to_add;
		to_add->next = *head;
		to_add->prev = NULL;
		*head = to_add;
	}
}

t_dlist	*lst_release_front(t_dlist **head, t_dlist **tail)
{
	t_dlist	*temp;

	if (!head || !*head)
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
t_dlist	*lst_release_back(t_dlist **head, t_dlist **tail)
{
	t_dlist	*temp;

	if (!head || !*head)
			return (NULL);
	if (*head == *tail)
	{
		temp = *tail;
		*head = NULL;
		*tail = NULL;
		return (temp);
	}
	temp = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	return (temp);
}
// swap_firsts needed - swaps 2 first elements in stacks.
void free_dlist(t_dlist **head, t_dlist **tail)
{
	t_dlist	*curr;
	t_dlist	*next;

	if (!head || !*head)
		return ;
	curr = *head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
	*tail = NULL;
}
