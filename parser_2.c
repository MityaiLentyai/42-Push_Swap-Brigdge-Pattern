/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:16:23 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/20 18:23:38 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1 means duplicate found --> ERROR; 0 means everything fine
int	check_duplicates(t_dlist *stack, int input_value)
{
	while (stack)
	{
		if (stack->value == input_value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	set_algo(t_state *state, t_algorithm algo)
{
	if (state->algorithm != NOT_SET)
		return (-1);
	state->algorithm = algo;
	return (1);
}

int	parse_flags(char *argv, t_state *state)
{
	if (ft_strncmp("--simple", argv, 9) == 0)
		return (set_algo(state, SIMPLE));
	if (ft_strncmp("--medium", argv, 9) == 0)
		return (set_algo(state, MEDIUM));
	if (ft_strncmp("--complex", argv, 10) == 0)
		return (set_algo(state, COMPLEX));
	if (ft_strncmp("--adaptive", argv, 11) == 0)
		return (set_algo(state, ADAPTIVE));
	if (ft_strncmp("--bench", argv, 8) == 0)
	{
		if (state->benchmark->to_print == 1)
			return (-1);
		state->benchmark->to_print = 1;
		return (1);
	}
	return (0);
}
