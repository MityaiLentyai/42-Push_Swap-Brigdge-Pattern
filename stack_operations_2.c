/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:23:40 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/21 15:27:29 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap A: Swap the first two elements at the top of stack A.
// Do nothing if there is only one or no elements.
void	sa(t_state *state)
{
	swap_two_first(&state->stack_a->head, &state->stack_a->tail);
	lst_add_back(create_node(SA), &state->operations->head,
		&state->operations->tail);
}

// Swap B: - Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements
void	sb(t_state *state)
{
	swap_two_first(&state->stack_b->head, &state->stack_b->tail);
	lst_add_back(create_node(SB), &state->operations->head,
		&state->operations->tail);
}

// Rotate B: Shift up all elements of stack B by one.
// The first element becomes the last one.
void	rb(t_state *state, int counter)
{
	t_dlist	*tmp;

	while (counter-- > 0)
	{
		tmp = lst_release_front(&state->stack_b->head, &state->stack_b->tail);
		lst_add_back(tmp, &state->stack_b->head, &state->stack_b->tail);
		lst_add_back(create_node(RB), &state->operations->head,
			&state->operations->tail);
	}
}

// Reverse Rotate B: Shift down all elements of stack b by one.
// The last element becomes the first one
void	rrb(t_state *state, int counter)
{
	t_dlist	*tmp;

	while (counter-- > 0)
	{
		tmp = lst_release_back(&state->stack_b->head, &state->stack_b->tail);
		lst_add_front(tmp, &state->stack_b->head, &state->stack_b->tail);
		lst_add_back(create_node(RRB), &state->operations->head,
			&state->operations->tail);
	}
}
