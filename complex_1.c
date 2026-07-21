/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:29:27 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/20 20:08:09 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quick_sort_a_help(t_state *state, int min, int median)
{
	int	numbers_to_push;
	int	numbers_to_rotate;

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
	return (numbers_to_rotate);
}

void	quick_sort_a(t_state *state, int min, int max)
{
	int	median;
	int	numbers_to_rotate;

	if (max - min + 1 <= 3)
	{
		small_stack_complex_a(state, max - min + 1);
		return ;
	}
	median = (max + min) / 2;
	numbers_to_rotate = quick_sort_a_help(state, min, median);
	if (numbers_to_rotate != (int)list_size(state->stack_a->head))
		rra(state, numbers_to_rotate);
	quick_sort_a(state, median + 1, max);
	quick_sort_b(state, min, median);
}

int	quick_sort_b_help(t_state *state, int max, int median)
{
	int	numbers_to_push;
	int	numbers_to_rotate;

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
	return (numbers_to_rotate);
}

void	quick_sort_b(t_state *state, int min, int max)
{
	int	median;
	int	numbers_to_rotate;

	if (max - min + 1 <= 3)
	{
		small_stack_complex_b(state, max - min + 1);
		return ;
	}
	median = (max + min) / 2;
	numbers_to_rotate = quick_sort_b_help(state, max, median);
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
	if (size_of_stack <= 5)
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
