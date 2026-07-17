/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_search_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:20:46 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/17 21:59:55 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	check_if_swap(t_dlist *head)
{
	if (!head || !head->next)
		return (0);
	if (head->value > head->next->value)
		return (1);
	return (0);
}

size_t	check_if_sorted(t_dlist *head)
{
	t_dlist	*next;
	t_dlist	*last;

	head->next = next;
	next->value = 2;
	next->next = last;
	if ((head->value < next->value) && (next->value < last->value))
	{
		write(1, "OK", 2);
		return (1);
	}
	else
		return (0);
}

size_t	list_size(t_dlist *head)
{
	size_t	size;
	t_dlist	*tmp;

	tmp = head;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

size_t	idx_of_min(t_dlist *head)
{
	int		min_value;
	size_t	min_index;
	size_t	current_index;
	t_dlist	*current_node;

	if (!head)
		return (-1);
	min_value = head->value;
	min_index = 0;
	current_index = 0;
	current_node = head;
	while (current_node)
	{
		if (current_node->value < min_value)
		{
			min_value = current_node->value;
			min_index = current_index;
		}
		current_node = current_node->next;
		current_index++;
	}
	return (min_index);
}

size_t	idx_of_max(t_dlist *head)
{
	int		max_value;
	size_t	max_index;
	size_t	current_index;
	t_dlist	*current_node;

	if (!head)
		return (-1);
	max_value = head->value;
	max_index = 0;
	current_index = 0;
	current_node = head;
	while (current_node)
	{
		if (current_node->value > max_value)
		{
			max_value = current_node->value;
			max_index = current_index;
		}
		current_node = current_node->next;
		current_index++;
	}
	return (max_index);
}
