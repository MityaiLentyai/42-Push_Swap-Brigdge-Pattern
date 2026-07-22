/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:25:44 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/21 18:06:30 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	size_t	i;

	if (!split || !*split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	single_number(long long input_value, t_state *state)
{
	t_dlist		*curr_node;

	if (input_value < INT_MIN || input_value > INT_MAX
		||check_duplicates(state->stack_a->head, input_value))
		return (1);
	curr_node = create_node(input_value);
	if (!curr_node)
		return (1);
	lst_add_back(curr_node, &(state->stack_a->head), &(state->stack_a->tail));
	return (0);
}

int	parse_numbers(char *argv, t_state *state)
{
	char		**arguments;
	char		**current;
	long long	input_value;

	arguments = ft_split(argv, ' ');
	if (!arguments || !*arguments)
	{
		free_split(arguments);
		return (0);
	}
	current = arguments;
	while (*current)
	{
		input_value = ft_atoi(*current);
		if (single_number(input_value, state))
		{
			free_split(arguments);
			return (1);
		}
		current++;
	}
	free_split(arguments);
	return (0);
}

int	error(t_state *state)
{
	free_state(&state);
	write(2, "Error\n", 6);
	return (1);
}

int	parse_input(int argc, char **argv, t_state *state)
{
	int	i;
	int	flag_set;
	int	numbers_started;

	i = 1;
	flag_set = 0;
	numbers_started = 0;
	while (i < argc)
	{
		flag_set = parse_flags(argv[i], state);
		if (flag_set == -1 || (flag_set == 1 && numbers_started == 1))
			return (error(state));
		if (flag_set == 0)
		{
			numbers_started = 1;
			if (parse_numbers(argv[i], state))
				return (error(state));
		}
		i++;
	}
	if (numbers_started == 0)
		return (1);
	if (state->algorithm == NOT_SET)
		state->algorithm = ADAPTIVE;
	return (0);
}
