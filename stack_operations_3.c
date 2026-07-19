/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:54:49 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/19 19:18:04 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// RR: ra and rb at the same time.
void	rr(t_state *state, int counter)
{
	t_dlist	*tmp;

	while (counter-- > 0)
	{
		tmp = lst_release_front(&state->stack_a->head, &state->stack_a->tail);
		lst_add_back(tmp, &state->stack_a->head, &state->stack_a->tail);
		tmp = lst_release_front(&state->stack_b->head, &state->stack_b->tail);
		lst_add_back(tmp, &state->stack_b->head, &state->stack_b->tail);
		lst_add_back(create_node(RR), &state->operations->head, &state->operations->tail);
	}
}

// SS: SA and SB at the same time.
void	ss(t_state *state)
{
	swap_two_first(&state->stack_a->head, &state->stack_a->tail);
	swap_two_first(&state->stack_b->head, &state->stack_b->tail);
	lst_add_back(create_node(SS), &state->operations->head, &state->operations->tail);
}

// RRR: rra and rrb at the same time
void	rrr(t_state *state, int counter)
{
	t_dlist	*tmp;

	while (counter-- > 0)
	{
		tmp = lst_release_back(&state->stack_a->head, &state->stack_a->tail);
		lst_add_front(tmp, &state->stack_a->head, &state->stack_a->tail);
		tmp = lst_release_back(&state->stack_b->head, &state->stack_b->tail);
		lst_add_front(tmp, &state->stack_b->head, &state->stack_b->tail);
		lst_add_back(create_node(RRR), &state->operations->head, &state->operations->tail);
	}
}
