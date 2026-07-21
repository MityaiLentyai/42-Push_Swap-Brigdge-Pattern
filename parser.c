/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:25:44 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/20 14:23:45 by nsuszano         ###   ########.fr       */
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
	if (!arguments)
		return (1);
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
