/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 03:25:52 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/17 16:57:32 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Small stack case handling - up to 5 elements

// We gotta check if our algorithms are working properly for small stacks.
// We can use a different approach for small stacks,
// as we can hardcode the solutions for 2, 3, 4, and 5 elements.
// This will make our program more efficient and faster for small stacks.

#include "push_swap.h"

void	small_stack(t_state *state)
{
	size_t	size_of_stack_a;

	size_of_stack_a = list_size(state->stack_a->head);
	if (size_of_stack_a == 1)
		return ;
	if (size_of_stack_a == 2)
	{
		if (check_if_swap(state->stack_a->head))
			sa(state);
		return ;
	}
	// for size == 3
}