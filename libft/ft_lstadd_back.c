/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:48:41 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 11:49:16 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list	**lst, t_list *new)
{
	t_list	*p;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		p = *lst;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

// int	main(void)
// {
// 	t_list	*t1 = ft_lstnew("Wiec");
// 	t_list	*t2 = ft_lstnew(" cos");
// 	t_list	*t3 = ft_lstnew(" tam");
// 	ft_lstadd_back(&t1, t2);
// 	ft_lstadd_back(&t1, t3);
// 	printf("%s", (char*)t1->content);
// 	printf("%s", (char*)t1->next->content);
// 	printf("%s\n", (char*)t1->next->next->content);

// 	t_list	**empty = NULL;
// 	ft_lstadd_back(empty, t1);
// 	printf("%p\n", empty);

// 	t_list	*emp = NULL;
// 	ft_lstadd_back(&emp, t1);
// 	printf("%s", (char*)emp->content);
// 	printf("%s", (char*)emp->next->content);
// 	free(t1);
// 	free(t2);
// 	free(t3);
// }