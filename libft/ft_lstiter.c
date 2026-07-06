/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:52:56 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:01:30 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void    f(void *content)
// {
//     printf("hello\n");
//     char *c = content;
//     *c++ = 'z';
//     *c = '\0';
//     return ;
// }

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// int	main(void)
// {
// 	char	s[] = "cos tam";
// 	t_list	*t = ft_lstnew(s);
// 	ft_lstiter(t,f);
// 	printf("%s\n", (char*)t->content);
// }