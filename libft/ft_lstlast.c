/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:53:44 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 11:53:57 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list	*t = ft_lstnew("cos tam");
// 	t_list	*add = ft_lstnew("Wiec ");
// 	printf("%p\n", ft_lstlast(NULL));
// 	printf("%s\n", (char*)ft_lstlast(add)->content);
// 	ft_lstadd_front(&t, add);
// 	printf("%s\n", (char*)ft_lstlast(t)->content);
// 	printf("%s", (char*)t->content);
// 	printf("%s\n", (char*)(t->next)->content);
// 	printf("%p\n", (t->next)->next);
// 	free(t);
// }