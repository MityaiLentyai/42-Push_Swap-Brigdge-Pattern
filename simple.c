/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 03:28:09 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/17 21:08:17 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// Selection sort 
void	simple(t_state *state)
{
	size_t	stack_size;
	size_t	min_idx;

	stack_size = list_size(state->stack_a->head);
	while (stack_size > 3)
	{
		min_idx = idx_of_min(state->stack_a->head);
		if (min_idx > (stack_size - 1) / 2)
			rra(state, stack_size - min_idx);
		else
			ra(state, min_idx);
		pb(state, 1);
		stack_size--;
	}
	small_stack(state);
	stack_size = list_size(state->stack_b->head);
	pa(state, stack_size);
}
