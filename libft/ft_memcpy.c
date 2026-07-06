/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:08:10 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:08:47 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*dest_u;
	unsigned char	*src_u;
	size_t			n;

	dest_u = (unsigned char *) dest;
	src_u = (unsigned char *) src;
	n = 0;
	while (n < count)
	{
		dest_u[n] = src_u[n];
		n++;
	}
	return (dest_u);
}

// int	main(void)
// {
// 	char	dest1[40] = "To poczatek...";
// 	char	src1[40] = "a to koniec!";
// 	ft_memcpy(dest1 + 5, dest1, 30);
// 	printf("%s\n", dest1);
// 	char	dest2[40] = "To poczatek...";
// 	char	src2[40] = "a to koniec!";
// 	memcpy(dest2 + 5, dest2, 30);
// 	printf("%s\n", dest2);
// }