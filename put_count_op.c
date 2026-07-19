#include "push_swap.h"

t_dlist	*find_sb(t_dlist *start)
{
	while (start)
	{
		if (start->value == SB)
			return (start);
		if (start->value == PB || start->value == RB || start->value == RRB || start->value == PA)
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
		if (start->value == PA || start->value == RA || start->value == RRA || start->value == PB)
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
		if (start->value == SB || start->value == PB || start->value == RRB || start->value == PA)
			return (NULL);
		start = start->next;
	}
	return (NULL);
}

t_dlist	*find_ra(t_dlist *start)
{
	while (start)
	{
		if (start->value == RA)
			return (start);
		if (start->value == PA || start->value == SA || start->value == RRA || start->value == PB)
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
		if (start->value == PB || start->value == RB || start->value == SB || start->value == PA)
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
		if (start->value == SA || start->value == RA || start->value == PA || start->value == PB)
			return (NULL);
		start = start->next;
	}
	return (NULL);
}

void	do_optimalization(t_dlist **operations, t_dlist **tail)
{
	t_dlist	*curr;
	t_dlist	*target;

	if (!operations || !*operations)
		return ;
	curr = *operations;
	while (curr)
	{
		target = NULL;
		if (curr->value == SA)
		{
			target = find_sb(curr->next);
			if (target)
			{
				lst_delete_middle_last(target, tail);
				curr->value = SS;
			}
		}
		else if (curr->value == SB)
		{
			target = find_sa(curr->next);
			if (target)
			{
				lst_delete_middle_last(target, tail);
				curr->value = SS;
			}
		}
		else if (curr->value == RA)
		{
			target = find_rb(curr->next);
			if (target)
			{
				lst_delete_middle_last(target, tail);
				curr->value = RR;
			}
		}
		else if (curr->value == RB)
		{
			target = find_ra(curr->next);
			if (target)
			{
				lst_delete_middle_last(target, tail);
				curr->value = RR;
			}
		}
		else if (curr->value == RRA)
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
		curr = curr->next;
	}
}

void	put_count_op(t_dlist **operations, t_dlist **tail, t_benchmark *bench)
{
	t_dlist	*curr;

	if(!*tail)
		return ;
	do_optimalization(operations, tail);
	if (!operations || !*operations)
		return ;
	curr = *operations;
	while (curr)
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
		else if (curr->value == RA)
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
		else if (curr->value == RRR)
		{
			write(1, "rrr\n", 4);
			bench->rrr++;
		}
		curr = curr->next;
	}
}
