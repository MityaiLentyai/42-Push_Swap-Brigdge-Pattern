/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:37:45 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 11:38:05 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

// int	main(void)
// {
// 	char	c1[] = "mam dl 8";
// 	char	c2[] = "mam dl 8";
// 	ft_bzero(c1 + 5, 3);
// 	bzero(c2 + 5, 3);
// 	printf("%s\n", c1);
// 	printf("%s\n", c2);
// }