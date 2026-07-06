/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:08:53 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/04 21:05:25 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*dest_u;
	unsigned char	*src_u;

	dest_u = (unsigned char *) dest;
	src_u = (unsigned char *) src;
	if (dest_u > src_u)
	{
		while (count > 0)
		{
			dest_u[count - 1] = src_u[count - 1];
			count--;
		}
	}
	else
	{
		ft_memcpy(dest_u, src_u, count);
	}
	return (dest_u);
}

// int	main(void)
// {
// 	char	dest1[40] = "To poczatek...";
// 	//char	src1[40] = "a to koniec!";
// 	ft_memmove(dest1 + 5, dest1, 20);
// 	printf("%s\n", dest1);
// 	char	dest2[40] = "To poczatek...";
// 	//char	src2[40] = "a to koniec!";
// 	memmove(dest2 + 5, dest2, 20);
// 	printf("%s\n", dest2);
// }