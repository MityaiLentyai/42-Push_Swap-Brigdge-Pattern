/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 03:25:52 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/19 21:01:29 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_state *state, t_dlist *head)
{
	if (check_if_sorted(state->stack_a->head))
		return ;
	if (head->value > head->next->value
		&& head->next->value < head->next->next->value
		&& head->value < head->next->next->value)
		sa(state);
	else if (head->value > head->next->value
		&& head->next->value < head->next->next->value
		&& head->value > head->next->next->value)
		ra(state, 1);
	else if (head->value < head->next->value
		&& head->next->value > head->next->next->value
		&& head->value < head->next->next->value)
	{
		rra(state, 1);
		sa(state);
	}
	else if (head->value < head->next->value
		&& head->next->value > head->next->next->value
		&& head->value > head->next->next->value)
		rra(state, 1);
	else
	{
		sa(state);
		rra(state, 1);
	}
}

static void	sort_five(t_state *state)
{
	size_t	current_size;
	size_t	min_idx;

	while (1)
	{
		current_size = list_size(state->stack_a->head);
		if (current_size <= 3)
			break ;
		min_idx = idx_of_min(state->stack_a->head);
		if (min_idx <= current_size / 2)
		{
			while (min_idx--)
				ra(state, 1);
		}
		else
		{
			while (min_idx++ < current_size)
				rra(state, 1);
		}
		pb(state, 1);
	}
	sort_three(state, state->stack_a->head);
	while (state->stack_b && state->stack_b->head)
		pa(state, 1);
}


static void	check_small_stack(t_state *state, t_dlist *head)
{
	size_t const	size_of_stack_a = list_size(head);

	if (!head || !head->next || !head->next->next)
		return ;
	if (size_of_stack_a == 3)
		sort_three(state, head);
	if (size_of_stack_a > 3 && size_of_stack_a <= 5)
		sort_five(state);
}

void	small_stack(t_state *state)
{
	size_t	size_of_stack_a;

	size_of_stack_a = list_size(state->stack_a->head);
	if (size_of_stack_a == 1)
		return ;
	if (size_of_stack_a == 2)
	{
		if (check_if_swap(state->stack_a->head))
			sa(state);
		return ;
	}
	if (size_of_stack_a >= 3 && size_of_stack_a <= 5)
	{
		if (check_if_sorted(state->stack_a->head))
			return ;
		check_small_stack(state, state->stack_a->head);
	}
}
