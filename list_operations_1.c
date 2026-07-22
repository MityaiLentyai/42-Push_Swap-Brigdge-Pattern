/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:22:23 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/21 15:29:36 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*create_node(int value)
{
	t_dlist	*new_node;

	new_node = malloc(sizeof(t_dlist));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	lst_add_back(t_dlist *to_add, t_dlist **head, t_dlist **tail)
{
	if (!head || !to_add)
		return ;
	if (!*head)
		lst_add_front(to_add, head, tail);
	else
	{
		(*tail)->next = to_add;
		to_add->prev = *tail;
		to_add->next = NULL;
		*tail = to_add;
	}
}

void	lst_add_front(t_dlist *to_add, t_dlist **head, t_dlist **tail)
{
	if (!head || !to_add)
		return ;
	if (!*head)
	{
		to_add->prev = NULL;
		to_add->next = NULL;
		*head = to_add;
		*tail = to_add;
	}
	else
	{
		(*head)->prev = to_add;
		to_add->next = *head;
		to_add->prev = NULL;
		*head = to_add;
	}
}

t_dlist	*lst_release_front(t_dlist **head, t_dlist **tail)
{
	t_dlist	*temp;

	if (!head || !*head)
		return (NULL);
	if (*head == *tail)
	{
		temp = *head;
		*head = NULL;
		*tail = NULL;
		return (temp);
	}
	temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	return (temp);
}

t_dlist	*lst_release_back(t_dlist **head, t_dlist **tail)
{
	t_dlist	*temp;

	if (!head || !*head)
		return (NULL);
	if (*head == *tail)
	{
		temp = *tail;
		*head = NULL;
		*tail = NULL;
		return (temp);
	}
	temp = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	return (temp);
}
