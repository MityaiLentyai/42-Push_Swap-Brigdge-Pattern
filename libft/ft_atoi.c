/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:33:35 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 11:37:19 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	minus;
	int	number;

	minus = 0;
	number = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus++;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = 10 * number - *nptr + '0';
		nptr++;
	}
	if (!minus)
		number = -number;
	return (number);
}

// int	main(void)
// {
// 	char	c[] = "  2147483647";
// 	c[0] = 9;
// 	printf("%d\n", ft_atoi(c));
// 	printf("%d\n", atoi(c));
// }
