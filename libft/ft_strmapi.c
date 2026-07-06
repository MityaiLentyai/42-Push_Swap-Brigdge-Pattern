/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:19:46 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 19:01:08 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	shifting(unsigned int n, char c)
// {
// 	return (c + n + 5);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*changed;
	unsigned int	s_len;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	changed = malloc(s_len + 1);
	if (!changed)
		return (NULL);
	changed[s_len] = '\0';
	while (s_len > 0)
	{
		s_len--;
		changed[s_len] = f(s_len, s[s_len]);
	}
	return (changed);
}

// int	main(void)
// {
// 	char	s[] = "aaaaaaaaaa";
// 	printf("%s\n", ft_strmapi(s,shifting));
// }