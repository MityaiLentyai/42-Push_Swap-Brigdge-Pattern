/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/18 17:29:27 by username         #+#    #+#              */
/*   Updated: 2026/07/18 18:45:34 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_stack_complex(t_state *state, t_dlist *head)
{
	size_t	size_of_stack;

	size_of_stack = list_size(head);
	if (size_of_stack == 1)
		return ;
	if (size_of_stack == 2)
	{
		if (check_if_swap(head))
			sa(state);
		return ;
	}
	if (size_of_stack == 3)
	{
		if (check_if_sorted(head))
			return ;
		sort_three_complex(state, head);
		return ;
	}
}

void	sort_three_complex(t_state *state, t_dlist *head)
{
	if (head->value > head->next->value
			&& head->next->value < head->next->next->value
	&& head->value < head->next->next->value)
	sa(state);
	else
	{
		if (head->value > head->next->value)
			sa(state);
		pb(state, 1);
		sa(state);
		pa(state, 1);
		if (head->value > head->next->value)
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
		small_stack_complex(state, state->stack_a->head);
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
	rra(state, numbers_to_rotate);
	quick_sort_a(state, median + 1, max);
	quick_sort_b(state, min, median - 1);
}

void	quick_sort_b(t_state *state, int min, int max)
{
	int	median;
	int	numbers_to_push;
	int	numbers_to_rotate;

	if (max - min + 1 <= 3)
	{
		small_stack_complex(state, state->stack_b->head);
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
	rrb(state, numbers_to_rotate);
	quick_sort_a(state, median + 1, max);
	quick_sort_b(state, min, median - 1);
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
