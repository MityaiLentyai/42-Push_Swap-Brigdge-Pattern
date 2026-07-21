/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:15:30 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/20 22:07:08 by dzzayats         ###   ########.fr       */
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