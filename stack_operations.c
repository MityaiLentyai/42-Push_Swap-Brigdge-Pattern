/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 21:45:52 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/08 21:45:52 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PA: take the first element from the top of B and place it at the top of A.
// Do nothing if B is empty.

void	pa(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!counter || !state)
		return ;
	if (!(state->stack_b->head))
		return ;
	tmp = lst_release_front(&state->stack_b->head,
			&state->stack_b->head);
	if (!tmp)
		return ;
	lst_add_front(tmp, &state->stack_a->head, &state->stack_a->tail);
	write(1, "PA\n", 3);
	state->benchmark->pa++;
}

// PB Take the first element at the top of a and put it ast the top of b.
// Do nothing if a is empty.

void	pb(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!counter || !state)
		return ;
	if (!(state->stack_a->head))
		return ;
	tmp = lst_release_front(&state->stack_a->head,
			&state->stack_a->tail);
	if (!tmp)
		return ;
	lst_add_front(tmp, &state->stack_b->head, &state->stack_b->tail);
	write(1, "PB\n", 3);
	state->benchmark->pb++;
}
// RA (rotate a): Shift up all elements of stack a by one.
// The first element becomes the last one.

void	ra(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!counter || !state)
		return ;
	if (!(state->stack_a->head) || (!(state->stack_a->tail)))
		return ;
	tmp = lst_release_front(&state->stack_a->head,
			&state->stack_a->tail);
	if (!tmp)
		return ;
	lst_add_back(tmp, &state->stack_a->head, &state->stack_a->tail);
	write(1, "RA\n", 3);
	state->benchmark->ra++;
}

// RRA (reverse rotate a): Shift down all elements of stack a by one.
// The last element becomes the first one.

void	rra(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!counter || !state)
		return ;
	if (!(state->stack_a->head) || (!(state->stack_a->tail)))
		return ;
	tmp = lst_release_back(&state->stack_a->head, &state->stack_a->tail);
	if (!tmp)
		return ;
	lst_add_front(tmp, &state->stack_a->head, &state->stack_a->tail);
	write(1, "RRA\n", 3);
	state->benchmark->rra++;
}
