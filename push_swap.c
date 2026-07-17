/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:27:00 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/17 19:42:36 by nsuszano         ###   ########.fr       */
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
	if (state->algorithm == SIMPLE)
		simple(state);
	else if (state->algorithm == MEDIUM)
		medium(state);
	else if (state->algorithm == COMPLEX)
		medium(state); //complex
	else if (state->algorithm == ADAPTIVE)
	{
		if (state->disorder < 0.2)
			simple(state);
		else if (state->disorder < 0.5)
			medium(state);
		else
			medium(state);	//complex
	}
	printf("Disorder: %.2f\n", state->disorder);
	medium(state);
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
			return (0);
	}
	printf("Before:\n");
	helper_main(state);
	return (0);
}
