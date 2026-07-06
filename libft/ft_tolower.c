/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:24:47 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:24:54 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

// int	main(void)
// {
// 	unsigned char	c = 'M';
// 	printf("%c\n", ft_tolower(c));
// 	printf("%c\n", tolower(c));
// 	printf("%c\n", c);
// }