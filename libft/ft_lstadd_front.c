/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:49:47 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:33:51 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*t = ft_lstnew("cos tam");
// 	t_list	*add = ft_lstnew("Wiec ");
// 	ft_lstadd_front(&t, add);
// 	if (t)
// 	{
// 		printf("%s", (char*)t->content);
// 		printf("%s\n", (char*)(t->next)->content);
// 		printf("%p\n", (t->next)->next);
// 	}
// 	free(add);
// 	free(t);
// }