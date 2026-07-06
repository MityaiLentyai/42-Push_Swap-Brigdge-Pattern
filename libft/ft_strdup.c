/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:15:30 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 19:00:30 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicated;
	char	*start;

	duplicated = malloc(ft_strlen(s) + 1);
	if (!duplicated)
		return (NULL);
	start = duplicated;
	while (*s)
	{
		*duplicated = *s;
		s++;
		duplicated++;
	}
	*duplicated = '\0';
	return (start);
}

// int	main(void)
// {
// 	char	s[] = "cos tam";
// 	printf("%s\n", ft_strdup(s));
// }