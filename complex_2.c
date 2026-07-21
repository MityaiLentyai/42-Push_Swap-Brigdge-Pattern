/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:28:11 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/20 20:09:11 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_stack_complex_a(t_state *state, int size_of_stack)
{
	if (size_of_stack == 1)
		return ;
	if (size_of_stack == 2)
	{
		if (check_if_swap(state->stack_a->head))
			sa(state);
		return ;
	}
	if (size_of_stack == 3)
	{
		if (state->stack_a->head->value < state->stack_a->head->next->value
			&& state->stack_a->head->next->value
			< state->stack_a->head->next->next->value
			&& state->stack_a->head->value
			< state->stack_a->head->next->next->value)
			return ;
		sort_three_complex_a(state);
	}
}

void	sort_three_complex_a(t_state *state)
{
	if (state->stack_a->head->value > state->stack_a->head->next->value
		&& state->stack_a->head->next->value
		< state->stack_a->head->next->next->value
		&& state->stack_a->head->value
		< state->stack_a->head->next->next->value)
		sa(state);
	else
	{
		if (state->stack_a->head->value > state->stack_a->head->next->value)
			sa(state);
		pb(state, 1);
		sa(state);
		pa(state, 1);
		if (state->stack_a->head->value > state->stack_a->head->next->value)
			sa(state);
	}
}

void	small_stack_complex_b(t_state *state, int size_of_stack)
{
	if (size_of_stack == 1)
		pa(state, 1);
	else if (size_of_stack == 2)
	{
		if (!check_if_swap(state->stack_b->head))
			sb(state);
		pa(state, 2);
	}
	else if (size_of_stack == 3)
	{
		pa(state, 3);
		small_stack_complex_a(state, 3);
	}
}
