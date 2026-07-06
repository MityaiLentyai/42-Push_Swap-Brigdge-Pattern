/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:20:19 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:20:31 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n > 0 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int	main(void)
// {
// 	char	s1[] = "cos";
// 	char	s2[] = "cos tam";
// 	s1[2] = -128;
// 	s2[2] = 128;
// 	// s2[3] = -89;
// 	printf("%d\n", ft_strncmp(s1, s2, 8));
// 	printf("%d\n", strncmp(s1, s2, 8));
// }