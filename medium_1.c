/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 14:32:35 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/20 17:58:03 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_into_array(int *list_copy, t_dlist *head)
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

	if (!head)
		return (1);
	list_length = list_size(head);
	list_copy = malloc(list_length * sizeof(int));
	if (!list_copy)
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

int	chunk_size_cal(int n)
{
	int	sqrt;

	sqrt = 0;
	while (sqrt * sqrt < n)
		sqrt++;
	return (sqrt);
}

void	from_a_to_b(t_state *state, int min_value, int chunk_size)
{
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
}

void	medium(t_state *state)
{
	int		chunk_size;
	int		min_value;
	size_t	max_idx;
	size_t	size_of_stack;

	size_of_stack = list_size(state->stack_a->head);
	if (size_of_stack <= 5)
		return (small_stack(state));
	if (change_numbers(state->stack_a->head))
		return ;
	chunk_size = chunk_size_cal(size_of_stack);
	min_value = 0;
	from_a_to_b(state, min_value, chunk_size);
	size_of_stack = list_size(state->stack_b->head);
	while (size_of_stack > 0)
	{
		max_idx = idx_of_max(state->stack_b->head);
		if (max_idx > (size_of_stack - 1) / 2)
			rrb(state, size_of_stack - max_idx);
		else
			rb(state, max_idx);
		pa(state, 1);
		size_of_stack--;
	}
}
