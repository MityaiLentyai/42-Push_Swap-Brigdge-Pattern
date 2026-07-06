/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:07:41 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:54:48 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (n > 0 && *st1 == *st2)
	{
		st1++;
		st2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*st1 - *st2);
}

// int	main(void)
// {
// 	char	s1[] = "cos tam";
// 	char	s2[] = "cos tam";
// 	s1[2] = -128;
// 	s2[2] = 128;
// 	s2[3] = -89;
// 	printf("%d\n", ft_memcmp(s1, s2, 8));
// 	printf("%d\n", memcmp(s1, s2, 8));
// }