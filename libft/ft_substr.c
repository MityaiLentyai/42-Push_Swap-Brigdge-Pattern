/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:24:25 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/20 22:27:25 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	idx;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start + 1 > s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	substr[idx] = '\0';
	return (substr);
}

// int	main(void)
// {
// 	char	s[] = "cos tam";
// 	printf("%s\n", ft_substr(s,8,3));
// }