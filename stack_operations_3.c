/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:54:49 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/17 18:33:47 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// RR ra and rb at the same time.

void	rr(t_state *state, int counter)
{
	t_dlist	*tmp;
	int		temp_counter;

	if (!state || !state->benchmark || !(state->stack_a) || !(state->stack_b))
		return ;
	temp_counter = counter;
	while (temp_counter-- > 0)
	{
		tmp = lst_release_front(&state->stack_a->head,
			&state->stack_a->tail);
		if (!tmp)
			return ;
		lst_add_back(tmp, &state->stack_a->head, &state->stack_a->tail);
	}
	temp_counter = counter;
	while (temp_counter-- > 0)
	{
		tmp = lst_release_front(&state->stack_b->head,
			&state->stack_b->tail);
		if (!tmp)
			return ;
		lst_add_back(tmp, &state->stack_b->head, &state->stack_b->tail);
	}
	state->benchmark->rra++;
	write(1, "RR\n", 4);
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
	swap_two_first(&state->stack_b->head, &state->stack_b->tail);
	swap_two_first(&state->stack_a->head, &state->stack_a->tail);
	write(1, "SS\n", 3);
	state->benchmark->ss++;
}

// RRR - rra and rrb at the same time

void	rrr(t_state *state, int counter)
{
	t_dlist	*tmp;
	int		temp_counter;

	temp_counter = counter;
	if (!state || !state->benchmark || !(state->stack_a) || !(state->stack_b))
		return ;
	while (temp_counter-- > 0)
	{
		tmp = lst_release_back(&state->stack_a->head, &state->stack_a->tail);
		if (!tmp)
			return ;
		lst_add_front(tmp, &state->stack_a->head, &state->stack_a->tail);
	}
	temp_counter = counter;
	while (temp_counter-- > 0)
	{
		tmp = lst_release_back(&state->stack_b->head, &state->stack_b->tail);
		if (!tmp)
			return ;
		lst_add_front(tmp, &state->stack_b->head, &state->stack_b->tail);
	}
	write(1, "RRR\n", 4);
	state->benchmark->rrr++;
}
