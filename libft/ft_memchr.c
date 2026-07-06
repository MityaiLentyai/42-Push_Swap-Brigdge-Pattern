/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:06:42 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 18:58:32 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	to_find;

	src = (unsigned char *)s;
	to_find = (unsigned char)c;
	while (n > 0)
	{
		if (*src == to_find)
			return (src);
		src++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "czas na kawe";
// 	s[1] = 128;
// 	printf("%s\n", (char*)ft_memchr(s, -128, 3));
// 	printf("%s\n", (char*)memchr(s, -128, 3));
// }