/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:29:27 by username          #+#    #+#             */
/*   Updated: 2026/07/19 14:38:46 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		sort_three_complex_a(state);
		return ;
	}
}

void	sort_three_complex_b(t_state *state)
{
	if (state->stack_b->head->value > state->stack_b->head->next->value
		&& state->stack_b->head->next->value < state->stack_b->head->next->next->value
		&& state->stack_b->head->value < state->stack_b->head->next->next->value)
		sb(state);
	else
	{
		if (state->stack_b->head->value > state->stack_b->head->next->value)
			sb(state);
		pa(state, 1);
		sb(state);
		pb(state, 1);
		if (state->stack_b->head->value > state->stack_b->head->next->value)
			sb(state);
	}
}

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
		if (check_if_sorted(state->stack_a->head))
			return ;
		sort_three_complex_a(state);
		return ;
	}
}

void	sort_three_complex_a(t_state *state)
{
	if (state->stack_a->head->value > state->stack_a->head->next->value
		&& state->stack_a->head->next->value < state->stack_a->head->next->next->value
		&& state->stack_a->head->value < state->stack_a->head->next->next->value)
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

void	quick_sort_a(t_state *state, int min, int max)
{
	int	median;
	int	numbers_to_push;
	int	numbers_to_rotate;

	if (max - min + 1 <= 3)
	{
		small_stack_complex_a(state, max - min + 1);
		return ;
	}
	median = (max + min) / 2;
	numbers_to_push = 0;
	numbers_to_rotate = 0;
	while (numbers_to_push < median - min + 1)
	{
		if (state->stack_a->head->value <= median)
		{
			pb(state, 1);
			numbers_to_push++;
		}
		else
		{
			ra(state, 1);
			numbers_to_rotate++;
		}
	}
	if (numbers_to_rotate != (int)list_size(state->stack_a->head))
		rra(state, numbers_to_rotate);
	quick_sort_a(state, median + 1, max);
	quick_sort_b(state, min, median);
}

void	quick_sort_b(t_state *state, int min, int max)
{
	int	median;
	int	numbers_to_push;
	int	numbers_to_rotate;

	if (max - min + 1 <= 3)
	{
		small_stack_complex_b(state, max - min + 1);
		return ;
	}
	median = (max + min) / 2;
	numbers_to_push = 0;
	numbers_to_rotate = 0;
	while (numbers_to_push < max - median)
	{
		if (state->stack_b->head->value > median)
		{
			pa(state, 1);
			numbers_to_push++;
		}
		else
		{
			rb(state, 1);
			numbers_to_rotate++;
		}
	}
	if (numbers_to_rotate != (int)list_size(state->stack_b->head))
		rrb(state, numbers_to_rotate);
	quick_sort_a(state, median + 1, max);
	quick_sort_b(state, min, median);
}

void	complex(t_state *state)
{
	int		min;
	int		max;
	size_t	size_of_stack;

	size_of_stack = list_size(state->stack_a->head);
	if (size_of_stack <= 3)
	{
		small_stack(state);
		return ;
	}
	if (change_numbers(state->stack_a->head))
		return ;
	min = 0;
	max = size_of_stack - 1;
	quick_sort_a(state, min, max);
}
