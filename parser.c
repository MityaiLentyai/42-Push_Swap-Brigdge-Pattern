/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:25:44 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/18 17:09:51 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1 means duplicate found --> ERROR; 0 means everything fine

size_t	check_duplicates(t_dlist *stack, int input_value)
{
	while (stack)
	{
		if (stack->value == input_value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

size_t	check_algorithm(char **argv, t_state *state)
{
	if (ft_strncmp("--simple", argv[1], ft_strlen(argv[1])) == 0)
	{
		if (state->algorithm != NOT_SET)
			return (1);
		state->algorithm = SIMPLE;
	}
	else if (ft_strncmp("--medium", argv[1], ft_strlen(argv[1])) == 0)
	{
		if (state->algorithm != NOT_SET)
			return (1);
		state->algorithm = MEDIUM;
	}
	else if (ft_strncmp("--complex", argv[1], ft_strlen(argv[1])) == 0)
	{
		if (state->algorithm != NOT_SET)
			return (1);
		state->algorithm = COMPLEX;
	}
	else if (ft_strncmp("--adaptive", argv[1], ft_strlen(argv[1])) == 0)
	{
		if (state->algorithm != NOT_SET)
			return (1);
		state->algorithm = ADAPTIVE;
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

// 0 means success, 1 means failure

int	parse_input(int argc, char **argv, t_state *state)
{
	int			i;
	char		**arguments;
	char		**current;
	long long	input_value;
	t_dlist		*curr_node;

	i = 1;
	if (check_algorithm(argv, state))
		return (1);
	if (state->algorithm == NOT_SET)
		state->algorithm = ADAPTIVE;
	else
		i++;
	if (i >= argc)
		return (1);
	if (ft_strncmp("--bench", argv[i], ft_strlen(argv[i])) == 0)
	{
		state->benchmark->to_print = 1;
		i++;
	}
	while (i < argc)
	{
		arguments = ft_split(argv[i], ' ');
		if (!arguments)
		{
			free_state(&state);
			write(2, "Error\n", 6);
			return (1);
		}
		current = arguments;
		while (*current)
		{
			input_value = ft_atoi(*current);
			// change atoi so it wouldnt accept input like 25cds
			if (input_value < INT_MIN || input_value > INT_MAX || check_duplicates(state->stack_a->head, input_value))
			{
				free_split(arguments);
				free_state(&state);
				write(2, "Error\n", 6);
				return (1);
			}
			curr_node = create_node(input_value);
			if (!curr_node)
			{
				free_split(arguments);
				free_state(&state);
				write(2, "Error\n", 6);
				return (1);
			}
			lst_add_back(curr_node, &(state->stack_a->head), &(state->stack_a->tail));
			current++;
		}
		free_split(arguments);
		i++;
	}
	return (0);
}
