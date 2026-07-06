/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:09:50 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:10:13 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*curr;

	curr = (unsigned char *) dest;
	while (count > 0)
	{
		curr[count - 1] = c;
		count--;
	}
	return (curr);
}

// int	main(void)
// {
// 	char	dest1[40] = "cos tam";
// 	char	dest2[40] = "cos tam";
// 	printf("%s\n", ft_memset(dest1, 'c', 3));
// 	printf("%s\n", memset(dest2, 'c', 3));
// }