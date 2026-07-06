/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:18:55 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 13:05:08 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size)
		dest[i] = '\0';
	return (len_src);
}

// int	main(void)
// {
// 	char	src1[40] = "Czas na kawe!";
// 	char	dest1[40] = "vhbjk";
// 	size_t size1 = ft_strlcpy(dest1, src1, -5);
// 	printf("%ld\n", size1);
// 	printf("%s\n", dest1);

// 	char	src2[40] = "Czas na kawe!";
// 	char	dest2[40] = "vhbjk";
// 	size_t size2 = ft_strlcpy(dest2, src2, -5);
// 	printf("%ld\n", size2);
// 	printf("%s\n", dest2);
// }