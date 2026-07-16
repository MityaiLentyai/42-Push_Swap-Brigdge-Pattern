/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:23:40 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/16 13:38:17 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SA Swap the first two elements at the top of stack A.
// Do nothing if there is only one or no elements.
// TODO add counter?
void	sa(t_state *state)
{
	if (!state || !state->benchmark || !(state->stack_a))
		return ;
	if (state->stack_a->head == state->stack_a->tail)
		return ;
	if (state->stack_a->head->value > state->stack_a->head->next->value)
	{
		swap_two_first(&state->stack_a->head, &state->stack_a->tail);
		write(1, "SA\n", 3);
		state->benchmark->sa++;
	}
}

// SB - Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements
// TODO? add counter?
void	sb(t_state *state)
{
	if (!state || !state->benchmark || !(state->stack_b))
		return ;
	if (state->stack_b->head == state->stack_b->tail)
		return ;
	if (state->stack_b->head->value > state->stack_b->head->next->value)
	{
		swap_two_first(&state->stack_b->head, &state->stack_b->tail);
		write(1, "SA\n", 3);
		state->benchmark->sb++;
	}
}

// RB - (rotate B): Shift up all elements of stack B by one. 
// The first element becomes the last one.
void	rb(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!state || !state->benchmark || !(state->stack_b))
		return ;
	while (counter > 0)
	{
		tmp = lst_release_front(&state->stack_b->head,
				&state->stack_b->tail);
		if (!tmp)
			return ;
		lst_add_back(tmp, &state->stack_b->head, &state->stack_b->tail);
		write(1, "RB\n", 3);
		state->benchmark->rb++;
		counter--;
	}
}

// RRB - (reverse rotate b): Shift down all elements of stack b by one. 
// The last element becomes the first one
void	rrb(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!state || !state->benchmark || !(state->stack_b))
		return ;
	while (counter > 0)
	{
		tmp = lst_release_back(&state->stack_b->head, &state->stack_b->tail);
		if (!tmp)
			return ;
		lst_add_front(tmp, &state->stack_b->head, &state->stack_b->tail);
		write(1, "RRB\n", 4);
		state->benchmark->rrb++;
		counter--;
	}
}
