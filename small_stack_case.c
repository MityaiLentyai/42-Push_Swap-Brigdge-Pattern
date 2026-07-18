/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 03:25:52 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/18 16:54:42 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Small stack case handling - up to 5 elements

// We gotta check if our algorithms are working properly for small stacks.
// We can use a different approach for small stacks,
// as we can hardcode the solutions for 2, 3, 4, and 5 elements.
// This will make our program more efficient and faster for small stacks.

#include "push_swap.h"

static void	sort_three(t_state *state, t_dlist *head)
{
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

static void	check_small_stack(t_state state,t_dlist *head)
{
	if (!head || !head->next || !head->next->next)
		return ;
	sort_three(&state, head);
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
	if (size_of_stack_a == 3)
	{
		if (check_if_sorted(state->stack_a->head))
			return ;
		check_small_stack(*state, state->stack_a->head);
		return ;
	}
}
