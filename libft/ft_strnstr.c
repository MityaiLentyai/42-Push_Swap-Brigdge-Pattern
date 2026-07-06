/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:21:06 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 19:01:28 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	curr_idx;
	size_t	little_len;

	curr_idx = 0;
	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (curr_idx + little_len <= len && big[curr_idx])
	{
		if (!ft_strncmp(&big[curr_idx], little, little_len))
			return ((char *)&big[curr_idx]);
		curr_idx++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	s1[] = "cdcdtamn";
// 	char	s2[] = "n";
// 	// s2[3] = -89;
// 	printf("%s\n", ft_strnstr(s1, s2, 8));
// 	printf("%s\n", strnstr(s1, s2, 8));
// }