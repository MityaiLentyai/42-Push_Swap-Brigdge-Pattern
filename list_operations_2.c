/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:24:33 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/10 02:24:33 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_dlist(t_dlist **head, t_dlist **tail)
{
	t_dlist	*curr;
	t_dlist	*next;

	if (!head || !*head)
		return ;
	curr = *head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
	*tail = NULL;
}

void	swap_two_first(t_dlist **head, t_dlist **tail)
{
	t_dlist	*first;
	t_dlist	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	if (second == *tail)
	{
		first->next = NULL;
		second->next = first;
		first->prev = second;
		second->prev = NULL;
		*head = second;
		*tail = first;
		return ;
	}
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	first->next->prev = first;
	*head = second;
}
