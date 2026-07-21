/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 22:26:49 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/21 14:04:12 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include "libft/libft.h"

int	which_operation(char *str, t_state *state)
{
	if (ft_strncmp("sa\n", str, 4) == 0)
		sa(state);
	else if (ft_strncmp("sb\n", str, 4) == 0)
		sb(state);
	else if (ft_strncmp("ss\n", str, 4) == 0)
		ss(state);
	else if (ft_strncmp("pa\n", str, 4) == 0)
		pa(state, 1);
	else if (ft_strncmp("pb\n", str, 4) == 0)
		pb(state, 1);
	else if (ft_strncmp("ra\n", str, 4) == 0)
		ra(state, 1);
	else if (ft_strncmp("rb\n", str, 4) == 0)
		rb(state, 1);
	else if (ft_strncmp("rr\n", str, 4) == 0)
		rr(state, 1);
	else if (ft_strncmp("rra\n", str, 5) == 0)
		rra(state, 1);
	else if (ft_strncmp("rrb\n", str, 5) == 0)
		rrb(state, 1);
	else if (ft_strncmp("rrr\n", str, 5) == 0)
		rrr(state, 1);
	else
		return (1);
	return (0);
}

int	help_main(t_state *state_ch)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		if (which_operation(operation, state_ch))
		{
			error(state_ch);
			free(operation);
			return (0);
		}
		free(operation);
		operation = get_next_line(0);
	}
	if (!check_if_sorted(state_ch->stack_a->head)
		|| state_ch->stack_b->head != NULL)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_state(&state_ch);
	free(operation);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_state	*state_ch;

	i = 1;
	if (argc < 2)
		return (0);
	state_ch = create_state();
	while (i < argc)
	{
		if (parse_numbers(argv[i], state_ch))
		{
			error(state_ch);
			return (0);
		}
		i++;
	}
	return (help_main(state_ch));
}
