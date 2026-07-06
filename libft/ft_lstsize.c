/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:05:55 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/03 12:06:28 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// int	main(void)
// {
// 	t_list	*t = ft_lstnew("cos tam");
// 	t_list	*add = ft_lstnew("Wiec ");
// 	t_list	*em = NULL;
// 	ft_lstadd_front(&t, add);
// 	if (t)
// 	{
// 		printf("%d\n", ft_lstsize(em));
// 		printf("%d\n", ft_lstsize(t));
// 		printf("%s", (char*)t->content);
// 		printf("%s\n", (char*)(t->next)->content);
// 		printf("%p\n", (t->next)->next);
// 	}
// 	free(add);
// 	free(t);
// }