/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:11:34 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 18:33:44 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec(unsigned int n, int fd)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		rec(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			c;

	c = '-';
	if (n < 0)
	{
		un = -(unsigned int)n;
		write(fd, &c, 1);
	}
	else
		un = (unsigned int)n;
	rec(un, fd);
}

// int	main(void)
// {
// 	ft_putnbr_fd(INT_MAX, 1);
// 	ft_putnbr_fd(INT_MIN, 1);
// 	ft_putnbr_fd(0, 1);
// 	ft_putnbr_fd(-45678, 1);
// }