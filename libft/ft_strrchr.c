/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:22:17 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 19:01:35 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	while (s >= start)
	{
		if (*s == (char) c)
			return ((char *)s);
		s--;
	}
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