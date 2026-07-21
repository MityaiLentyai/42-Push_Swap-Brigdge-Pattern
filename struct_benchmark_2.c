/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_benchmark_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:00:45 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/20 18:48:58 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_double(int fd, double value)
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

//Could've used \u221A instead of sqrt, but norm does not allow it :((
void	write_algorithm_name(int fd, t_algorithm algo, double disorder)
{
	ft_putstr_fd("[bench] strategy: ", fd);
	if (algo == SIMPLE)
		ft_putstr_fd("Simple / (O(n^2))", fd);
	else if (algo == MEDIUM)
		ft_putstr_fd("Medium / (O(n sqrt n))", fd);
	else if (algo == COMPLEX)
		ft_putstr_fd("Complex / (O(n log n))", fd);
	else if (algo == ADAPTIVE)
	{
		if (disorder < 0.2)
			ft_putstr_fd("Adaptive / (O(n^2))", fd);
		else if (disorder >= 0.2 && disorder < 0.5)
			ft_putstr_fd("Adaptive / (O(n sqrt n))", fd);
		else if (disorder >= 0.5)
			ft_putstr_fd("Adaptive / (O(n log n))", fd);
	}
	ft_putstr_fd("\n", fd);
}
