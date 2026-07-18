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

// Push A: take the first element from the top of B and place it at the top of A
// Do nothing if B is empty.
void	pa(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!state || !state->benchmark || !state->stack_a || !state->stack_b)
		return ;
	while (counter > 0)
	{
		tmp = lst_release_front(&state->stack_b->head,
				&state->stack_b->tail);
		if (!tmp)
			return ;
		lst_add_front(tmp, &state->stack_a->head, &state->stack_a->tail);
		write(1, "pa\n", 3);
		state->benchmark->pa++;
		counter--;
	}
}

// Push B: Take the first element at the top of A and put it ast the top of B.
// Do nothing if A is empty.
void	pb(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!state || !state->benchmark || !(state->stack_b))
		return ;
	while (counter > 0)
	{
		tmp = lst_release_front(&state->stack_a->head,
				&state->stack_a->tail);
		if (!tmp)
			return ;
		lst_add_front(tmp, &state->stack_b->head, &state->stack_b->tail);
		write(1, "pb\n", 3);
		state->benchmark->pb++;
		counter--;
	}
}

// Rotate A: Shift up all elements of stack a by one.
// The first element becomes the last one.
void	ra(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!state || !state->benchmark || !(state->stack_a))
		return ;
	while (counter > 0)
	{
		tmp = lst_release_front(&state->stack_a->head,
				&state->stack_a->tail);
		if (!tmp)
			return ;
		lst_add_back(tmp, &state->stack_a->head, &state->stack_a->tail);
		write(1, "ra\n", 3);
		state->benchmark->ra++;
		counter--;
	}
}

// Reverse Rotate A: Shift down all elements of stack A by one.
// The last element becomes the first one.
void	rra(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!state || !state->benchmark || !(state->stack_a))
		return ;
	while (counter > 0)
	{
		tmp = lst_release_back(&state->stack_a->head, &state->stack_a->tail);
		if (!tmp)
			return ;
		lst_add_front(tmp, &state->stack_a->head, &state->stack_a->tail);
		write(1, "rra\n", 4);
		state->benchmark->rra++;
		counter--;
	}
}
