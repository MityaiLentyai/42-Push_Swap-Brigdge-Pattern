/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:25:06 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:25:13 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

// int	main(void)
// {
// 	unsigned char	c = 'm';
// 	printf("%c\n", ft_toupper(c));
// 	printf("%c\n", toupper(c));
// 	printf("%c\n", c);
// }
