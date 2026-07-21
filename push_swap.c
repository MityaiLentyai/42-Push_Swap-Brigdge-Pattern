/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:27:00 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/20 16:57:12 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	helper_main(t_state *state)
{
	state->disorder = compute_disorder(state->stack_a);
	if (state->disorder != 0)
	{
		if (state->algorithm == SIMPLE)
			simple(state);
		else if (state->algorithm == MEDIUM)
			medium(state);
		else if (state->algorithm == COMPLEX)
			complex(state);
		else if (state->algorithm == ADAPTIVE)
		{
			if (state->disorder < 0.2)
				simple(state);
			else if (state->disorder < 0.5)
				medium(state);
			else
				complex(state);
		}
	}
	put_count_op(&state->operations->head,
		&state->operations->tail, state->benchmark);
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
	helper_main(state);
	return (0);
}
