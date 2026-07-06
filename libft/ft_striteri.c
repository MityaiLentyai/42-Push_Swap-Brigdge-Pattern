/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:16:33 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:26:59 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	shifting(unsigned int n, char *s)
// {
// 	*s += n + 5;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	idx;

	if (!s || !f)
		return ;
	idx = 0;
	while (s[idx])
	{
		f(idx, &(s[idx]));
		idx++;
	}
}

// int	main(void)
// {
// 	char	s[] = "aaaaaaaaaa";
// 	ft_striteri(s, shifting);
// 	printf("%s\n", s);
// }