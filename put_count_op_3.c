/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_count_op_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 20:24:32 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/20 20:25:36 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*find_ra(t_dlist *start)
{
	while (start)
	{
		if (start->value == RA)
			return (start);
		if (start->value == PA || start->value == SA || start->value == RRA
			|| start->value == PB)
			return (NULL);
		start = start->next;
	}
	return (NULL);
}

t_dlist	*find_rrb(t_dlist *start)
{
	while (start)
	{
		if (start->value == RRB)
			return (start);
		if (start->value == PB || start->value == RB || start->value == SB
			|| start->value == PA)
			return (NULL);
		start = start->next;
	}
	return (NULL);
}

t_dlist	*find_rra(t_dlist *start)
{
	while (start)
	{
		if (start->value == RRA)
			return (start);
		if (start->value == SA || start->value == RA || start->value == PA
			|| start->value == PB)
			return (NULL);
		start = start->next;
	}
	return (NULL);
}

void	check_ss(t_dlist *curr, t_dlist **tail)
{
	t_dlist	*target;

	if (curr->value == SA)
	{
		target = find_sb(curr->next);
		if (target)
		{
			lst_delete_middle_last(target, tail);
			curr->value = SS;
		}
	}
	if (curr->value == SB)
	{
		target = find_sa(curr->next);
		if (target)
		{
			lst_delete_middle_last(target, tail);
			curr->value = SS;
		}
	}
}

void	check_rr(t_dlist *curr, t_dlist **tail)
{
	t_dlist	*target;

	if (curr->value == RA)
	{
		target = find_rb(curr->next);
		if (target)
		{
			lst_delete_middle_last(target, tail);
			curr->value = RR;
		}
	}
	if (curr->value == RB)
	{
		target = find_ra(curr->next);
		if (target)
		{
			lst_delete_middle_last(target, tail);
			curr->value = RR;
		}
	}
}
