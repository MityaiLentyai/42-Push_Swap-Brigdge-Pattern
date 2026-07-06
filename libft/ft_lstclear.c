/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:50:19 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 11:50:52 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !del)
		return ;
	next = *lst;
	while (next)
	{
		temp = next;
		next = (next)->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}

// int	main(void)
// {
// 	t_list	*t = ft_lstnew("cos tam");
// 	ft_lstclear(&t,d);
// 	printf("%p", t);
// }