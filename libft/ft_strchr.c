/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:14:26 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/21 13:34:32 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	char	s[256];
// 	for (int i = -128; i < 128; i++)
// 		s[i + 128] = i;
// 	for (int i = -128; i < 128; i++)
// 		printf("%d\n", s[i + 128]);
// 	char s[2];
// 	s[0] = -128;
// 	printf("%p\n", ft_strchr(s, 128));
// 	printf("%p", strchr(s, 128));
// 	if (ft_strchr(s, 'i') == strchr(s, 'i'))
// 		printf("ok\n");
// 	printf("%s\n", ft_strchr(s, 124));
// 	printf("%s\n", strchr(s, '\0'));
// }
