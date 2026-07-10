/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:27:00 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/10 12:42:09 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	helper_main(t_state *state)
{
	t_dlist	*current;

	current = state->stack_a->head;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	state->disorder = compute_disorder(state->stack_a);
	printf("Disorder: %.2f\n", state->disorder);
	simple(state);
	printf("After:\n");
	current = state->stack_a->head;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	call_benchmark(state);
	free_state(&state);
}

int	main(int argc, char **argv)
{
	t_state	*state;

	if (argc < 2)
		return (0);
	else
	{
		state = create_state();
		if (!state || parse_input(argc, argv, state))
		{
			// Handle error in parsing input
			return (1);
		}
	}
	printf("Before:\n");
	helper_main(state);
	return (0);
}
