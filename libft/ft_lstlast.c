/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:53:44 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/06 17:15:02 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_lstlast(t_dlist *lst)
{
        t_dlist *temp;
        
	while (lst && lst->next)
        {
                temp = lst;
		lst = lst->next;
                lst->prev = temp;
        }
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