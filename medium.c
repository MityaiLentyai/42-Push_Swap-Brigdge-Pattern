/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 14:32:35 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/17 16:56:03 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int(int *tab, size_t n)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = n - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

void list_into_array(int *list_copy, t_dlist *head)
{
	size_t	idx;

	idx = 0;
	while (head)
	{
		list_copy[idx] = head->value;
		head = head->next;
		idx++;	
	}
}

// 1 when malloc failed
size_t	change_numbers(t_dlist *head)
{
	size_t	list_length;
	int		*list_copy;

	if (!head)	// but there is no such possibility that head is empty at this point of program
		return (1);	// if so then is would already been stopped 
	list_length = list_size(head);
	list_copy = malloc(list_length*sizeof(int));
	if (list_copy)
		return (1);
	list_into_array(list_copy, head);
	sort_int(list_copy, list_length);
	while (head)
	{
		list_length = 0;
		while (head->value != list_copy[list_length])
			list_length++;
		head->value = list_length;
		head = head->next;	
	}
	free(list_copy);
	return (0);
}

size_t	chunk_size_cal(size_t n)
{
	size_t sqrt;

	sqrt = 0;
	while (sqrt * sqrt < n)
		sqrt++;
	return (sqrt);
}
// same as above - no chance that state is NULL

void	medium(t_state *state)
{
	size_t	chunk_size;
	size_t	min_value;	// numbers changed --> from 0 to size - 1; like indexes in array
	size_t	size_of_stack;
	size_t	max_idx;
	
	size_of_stack = list_size(state->stack_a->head);
	if (size_of_stack <= 3)
		return small_stack(state);
	if (change_numbers(state->stack_a->head))
		return ;
	chunk_size = chunk_size_cal(size_of_stack);
	min_value = 0;
	while (state->stack_a->head)
	{
		if (state->stack_a->head->value <= min_value)
		{
			pb(state, 1);
			rb(state, 1);
			min_value++;
		}
		else if (state->stack_a->head->value <= min_value + chunk_size)
		{
			pb(state, 1);
			min_value++;
		}
		else
			ra(state, 1);
	}
	size_of_stack = list_size(state->stack_b->head);
	while (size_of_stack > 0)
	{
		max_idx = idx_of_max(state->stack_b->head);
		if (max_idx > (size_of_stack - 1) / 2)
			rra(state, size_of_stack - max_idx);
		else
			ra(state, max_idx);
		pb(state, 1);
		size_of_stack--;	
	}
}

