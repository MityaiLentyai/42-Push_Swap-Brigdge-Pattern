/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:23:40 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/16 12:36:28 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		state->benchmark->sa++;
	}
}

// SS - SA and SB at the same time.
// ??? do we do part of it (sa/sb separately?) if either one fails,Looks unfair
void	ss(t_state *state)
{
	if (!state || !state->benchmark
		|| !(state->stack_b) || !(state->stack_a))
		return ;
	if (state->stack_a->head == state->stack_a->tail)
		return ;
	if (state->stack_b->head == state->stack_b->tail)
		return ;
	sa(state);
	sb(state);
}
