/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_benchmark.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 03:26:58 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/19 00:53:07 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_benchmark	*create_benchmark(void)
{
	t_benchmark	*bench;

	bench = malloc(sizeof(t_benchmark));
	if (!bench)
		return (NULL);
	bench->to_print = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	return (bench);
}

static void	write_double(int fd, double value)
{
	double	percentage;
	int		integer_part;
	int		decimal_part;

	percentage = value * 100;
	integer_part = (int) percentage;
	decimal_part = (int)((percentage - integer_part) * 100);
	if (decimal_part < 0)
		decimal_part = -decimal_part;
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(integer_part, fd);
	ft_putstr_fd(".", fd);
	if (decimal_part < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(decimal_part, fd);
	ft_putstr_fd("%\n", fd);
}

static void	write_algorithm_name(int fd, t_algorithm algo)
{
	ft_putstr_fd("[bench] strategy: ", fd);
	if (algo == SIMPLE)
		ft_putstr_fd("Simple / (O(n^2))", fd);
	else if (algo == MEDIUM)
		ft_putstr_fd("Medium / (O(n sqquare root n))", fd);
	else if (algo == COMPLEX)
		ft_putstr_fd("Complex / (O(n log n))", fd);
	else if (algo == ADAPTIVE)
		ft_putstr_fd("Aadaptive / (O(n it depends n))", fd);
	else
		ft_putstr_fd("UNKNOWN", fd);
	ft_putstr_fd("\n", fd);
}

static void	write_total_operations(int fd, t_benchmark *bench)
{
	size_t	total;

	total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb
	+bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb
	+bench->rrr;
	ft_putstr_fd("[bench] total_ops: ", fd);
	ft_putnbr_fd(total, fd);
	ft_putstr_fd("\n", fd);
}

static void	write_operation_counts(int fd, t_benchmark *bench)
{
	ft_putstr_fd("[bench]", fd);
	ft_putstr_fd(" sa: ", fd);
	ft_putnbr_fd(bench->sa, fd);
	ft_putstr_fd(" sb: ", fd);
	ft_putnbr_fd(bench->sb, fd);
	ft_putstr_fd("  ss: ", fd);
	ft_putnbr_fd(bench->ss, fd);
	ft_putstr_fd("  pa: ", fd);
	ft_putnbr_fd(bench->pa, fd);
	ft_putstr_fd("  pb: ", fd);
	ft_putnbr_fd(bench->pb, fd);
	ft_putstr_fd("\n[bench] ra: ", fd);
	ft_putnbr_fd(bench->ra, fd);
	ft_putstr_fd("  rb: ", fd);
	ft_putnbr_fd(bench->rb, fd);
	ft_putstr_fd("  rr: ", fd);
	ft_putnbr_fd(bench->rr, fd);
	ft_putstr_fd("  rra: ", fd);
	ft_putnbr_fd(bench->rra, fd);
	ft_putstr_fd("  rrb: ", fd);
	ft_putnbr_fd(bench->rrb, fd);
	ft_putstr_fd("  rrr: ", fd);
	ft_putnbr_fd(bench->rrr, fd);
	ft_putstr_fd("\n", fd);
}

void	call_benchmark(t_state *state)
{
	if (!state || !state->benchmark || !state->benchmark->to_print)
		return ;
	write_double(2, state->disorder);
	write_algorithm_name(2, state->algorithm);
	write_total_operations(2, state->benchmark);
	write_operation_counts(2, state->benchmark);
}

void	free_benchmark(t_benchmark **benchmark)
{
	if (!benchmark || !*benchmark)
		return ;
	free(*benchmark);
	*benchmark = NULL;
}
