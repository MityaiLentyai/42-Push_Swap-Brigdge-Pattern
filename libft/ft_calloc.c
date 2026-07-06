/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:38:18 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 18:50:54 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (__SIZE_MAX__ / size < nmemb)
		return (NULL);
	total_size = nmemb * size;
	str = malloc(total_size);
	if (str)
		str = ft_memset(str, 0, total_size);
	return (str);
}

// int	main(void)
// {
// 	int	*r;
// 	r = ft_calloc(5,4);
// 	printf("%s\n", (char*)ft_calloc(5,4));
// 	while(*r)
// 	{
// 		printf("%d ", *r);
// 		r++;
// 	}
// }