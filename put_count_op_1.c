/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_count_op_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:32:11 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/20 20:24:44 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rrr(t_dlist *curr, t_dlist **tail)
{
	t_dlist	*target;

	if (curr->value == RRA)
	{
		target = find_rrb(curr->next);
		if (target)
		{
			lst_delete_middle_last(target, tail);
			curr->value = RRR;
		}
	}
	else if (curr->value == RRB)
	{
		target = find_rra(curr->next);
		if (target)
		{
			lst_delete_middle_last(target, tail);
			curr->value = RRR;
		}
	}
}

void	do_optimalization(t_dlist **operations, t_dlist **tail)
{
	t_dlist	*curr;

	if (!operations || !*operations)
		return ;
	curr = *operations;
	while (curr)
	{
		check_ss(curr, tail);
		check_rr(curr, tail);
		check_rrr(curr, tail);
		curr = curr->next;
	}
}

void	count_write1(t_dlist *curr, t_benchmark *bench)
{
	if (curr->value == SA)
	{
		write(1, "sa\n", 3);
		bench->sa++;
	}
	else if (curr->value == SB)
	{
		write(1, "sb\n", 3);
		bench->sb++;
	}
	else if (curr->value == SS)
	{
		write(1, "ss\n", 3);
		bench->ss++;
	}
	else if (curr->value == PA)
	{
		write(1, "pa\n", 3);
		bench->pa++;
	}
	else if (curr->value == PB)
	{
		write(1, "pb\n", 3);
		bench->pb++;
	}
}

void	count_write2(t_dlist *curr, t_benchmark *bench)
{
	if (curr->value == RA)
	{
		write(1, "ra\n", 3);
		bench->ra++;
	}
	else if (curr->value == RB)
	{
		write(1, "rb\n", 3);
		bench->rb++;
	}
	else if (curr->value == RR)
	{
		write(1, "rr\n", 3);
		bench->rr++;
	}
	else if (curr->value == RRA)
	{
		write(1, "rra\n", 4);
		bench->rra++;
	}
	else if (curr->value == RRB)
	{
		write(1, "rrb\n", 4);
		bench->rrb++;
	}
}

void	put_count_op(t_dlist **operations, t_dlist **tail, t_benchmark *bench)
{
	t_dlist	*curr;

	if (!*tail)
		return ;
	do_optimalization(operations, tail);
	if (!operations || !*operations)
		return ;
	curr = *operations;
	while (curr)
	{
		count_write1(curr, bench);
		count_write2(curr, bench);
		if (curr->value == RRR)
		{
			write(1, "rrr\n", 4);
			bench->rrr++;
		}
		curr = curr->next;
	}
}
