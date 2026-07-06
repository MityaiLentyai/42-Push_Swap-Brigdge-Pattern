/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:23:41 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 19:01:45 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*find_start(char const *s1, char const *set)
{
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	return (s1);
}

static size_t	find_len(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;

	start = s1;
	end = s1;
	while (*end)
		end++;
	end--;
	while (end > start && ft_strchr(set, *end))
		end--;
	while (start < end && ft_strchr(set, *start))
		start++;
	if (start == end && ft_strchr(set, *start))
		return (0);
	return (end - start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char		*trimmed;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	len = find_len(s1, set);
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (NULL);
	start = find_start(s1, set);
	ft_strlcpy(trimmed, start, len + 1);
	return (trimmed);
}

// int	main(void)
// {
// 	char	s1[] = "aaabbbc";
// 	char	set[] = "abc";
// 	printf("%s\n", ft_strtrim(s1,set));
// }