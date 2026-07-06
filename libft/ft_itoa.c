/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:45:08 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 18:57:42 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(unsigned int un)
{
	size_t			order;

	order = 0;
	if (!un)
		order++;
	while (un > 0)
	{
		order++;
		un /= 10;
	}
	return (order);
}

static unsigned int	abs_int(int n)
{
	if (n < 0)
		return (-(unsigned int)n);
	else
		return ((unsigned int)n);
}

char	*ft_itoa(int n)
{
	char			*number;
	unsigned int	un;
	size_t			order;

	un = abs_int(n);
	order = count_digits(un);
	if (n < 0)
		order++;
	number = malloc(order + 1);
	if (!number)
		return (NULL);
	number[order] = '\0';
	while (order > 0)
	{
		order--;
		number[order] = un % 10 + '0';
		un /= 10;
	}
	if (n < 0)
		number[0] = '-';
	return (number);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(INT_MIN));
// 	printf("%s\n", ft_itoa(INT_MAX));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-12678));
// }