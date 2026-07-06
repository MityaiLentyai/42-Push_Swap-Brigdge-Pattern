/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:19:27 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:19:35 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

// int	main(void)
// {
// 	char	c[] = "mam dl 8";
// 	printf("%ld\n", ft_strlen(c));
// 	printf("%ld\n", strlen(c));
// }