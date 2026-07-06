/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:11:10 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:32:14 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	char	c;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
	c = '\n';
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putendl_fd("cos tam", 1);
// }