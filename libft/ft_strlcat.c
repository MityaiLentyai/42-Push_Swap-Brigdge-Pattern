/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:38:37 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 15:42:30 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;

	len_dest = 0;
	while (dest[len_dest] && len_dest < size)
		len_dest++;
	len_src = ft_strlen(src);
	i = 0;
	while (src[i] && i + len_dest + 1 < size)
	{
		dest[i + len_dest] = src[i];
		i++;
	}
	if (i + len_dest < size)
		dest[i + len_dest] = '\0';
	return (len_dest + len_src);
}

// int	main(void)
// {
// 	char	src1[40] = "Czas na kawe!";
// 	char	dest1[40] = "raz";
// 	size_t size1 = ft_strlcat(dest1, src1, 5);
// 	printf("%ld\n", size1);
// 	printf("%s\n", dest1);

// 	char	src2[40] = "Czas na kawe!";
// 	char	dest2[40] = "raz";
// 	size_t size2 = ft_strlcat(dest2, src2, 5);
// 	printf("%ld\n", size2);
// 	printf("%s\n", dest2);
// }