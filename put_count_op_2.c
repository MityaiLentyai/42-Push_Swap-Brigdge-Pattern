/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_count_op_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:33:41 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/20 18:45:21 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*find_sb(t_dlist *start)
{
	while (start)
	{
		if (start->value == SB)
			return (start);
		if (start->value == PB || start->value == RB || start->value == RRB
			|| start->value == PA)
			return (NULL);
		start = start->next;
	}
	return (NULL);
}

t_dlist	*find_sa(t_dlist *start)
{
	while (start)
	{
		if (start->value == SA)
			return (start);
		if (start->value == PA || start->value == RA || start->value == RRA
			|| start->value == PB)
			return (NULL);
		start = start->next;
	}
	return (NULL);
}

t_dlist	*find_rb(t_dlist *start)
{
	while (start)
	{
		if (start->value == RB)
			return (start);
		if (start->value == SB || start->value == PB || start->value == RRB
			|| start->value == PA)
			return (NULL);
		start = start->next;
	}
	return (NULL);
}
