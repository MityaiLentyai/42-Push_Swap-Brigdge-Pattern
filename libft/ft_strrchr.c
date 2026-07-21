/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:22:17 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/20 22:06:02 by dzzayats         ###   ########.fr       */
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
// 	char	s[40] = "czas na kawe";
// 	if (ft_strrchr(s, 'i') == strrchr(s, 'i'))
// 		printf("ok\n");
// 	printf("%s\n", ft_strrchr(s, '\0'));
// 	printf("%s\n", strrchr(s, '\0'));
// }