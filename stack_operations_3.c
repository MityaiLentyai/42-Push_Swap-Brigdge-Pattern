/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:54:49 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/16 14:03:44 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// RR ra and rb at the same time.

void	rr(t_state *state, int counter)
{
	if (!state || !state->benchmark || !(state->stack_a))
		return ;
	if (!state || !state->benchmark || !(state->stack_b))
		return ;
	ra(state, counter);
	rb(state, counter);
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

// RRR - rra and rrb at the same time

void	rrr(t_state *state, int counter)
{
	if (!state || !state->benchmark || !(state->stack_a))
		return ;
	if (!state || !state->benchmark || !(state->stack_b))
		return ;
	rra(state, counter);
	rrb(state, counter);
}
