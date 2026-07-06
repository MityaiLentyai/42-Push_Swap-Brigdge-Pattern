/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:00:51 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/04 21:28:47 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void    *f(void *content)
// {
//     printf("hello\n");
//     char *c = content;
//     *c++ = 'z';
//     *c = '\0';
//     return c;
// }

// void    d(void *content)
// {
//     printf("hello\n");
//     return ;
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	if (!f)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// int main(void)
// {
// 	char	s[] = "cos tam";
//     t_list  *t = ft_lstnew(s);
//     ft_lstmap(t,f,d);
//     printf("%s\n", (char*)t->content);
// }