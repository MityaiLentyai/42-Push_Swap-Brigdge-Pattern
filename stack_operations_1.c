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

	while (counter-- > 0)
	{
		tmp = lst_release_front(&state->stack_b->head, &state->stack_b->tail);
		lst_add_front(tmp, &state->stack_a->head, &state->stack_a->tail);
		lst_add_back(create_node(PA), &state->operations->head, &state->operations->tail);
	}
}

// Push B: Take the first element at the top of A and put it ast the top of B.
// Do nothing if A is empty.
void	pb(t_state *state, int counter)
{
	t_dlist	*tmp;

	while (counter-- > 0)
	{
		tmp = lst_release_front(&state->stack_a->head,
				&state->stack_a->tail);
		lst_add_front(tmp, &state->stack_b->head, &state->stack_b->tail);
		lst_add_back(create_node(PB), &state->operations->head, &state->operations->tail);
	}
}

// Rotate A: Shift up all elements of stack a by one.
// The first element becomes the last one.
void	ra(t_state *state, int counter)
{
	t_dlist	*tmp;

	while (counter-- > 0)
	{
		tmp = lst_release_front(&state->stack_a->head,
				&state->stack_a->tail);
		lst_add_back(tmp, &state->stack_a->head, &state->stack_a->tail);
		lst_add_back(create_node(RA), &state->operations->head, &state->operations->tail);
	}
}

// Reverse Rotate A: Shift down all elements of stack A by one.
// The last element becomes the first one.
void	rra(t_state *state, int counter)
{
	t_dlist	*tmp;

	while (counter-- > 0)
	{
		tmp = lst_release_back(&state->stack_a->head, &state->stack_a->tail);
		lst_add_front(tmp, &state->stack_a->head, &state->stack_a->tail);
		lst_add_back(create_node(RRA), &state->operations->head, &state->operations->tail);
	}
}
