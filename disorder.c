/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:05:13 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/19 00:46:14 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack)
{
	unsigned int	mistakes;
	unsigned int	total_pairs;
	t_dlist			*tmp1;
	t_dlist			*tmp2;

	mistakes = 0;
	total_pairs = 0;
	if (!stack)
		return (0);
	tmp1 = stack->head;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			total_pairs++;
			if (tmp1->value > tmp2->value)
				mistakes++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	if (total_pairs)
		return ((double) mistakes / (double) total_pairs);
	return (0);
}
