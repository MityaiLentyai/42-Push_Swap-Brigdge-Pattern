/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:05:13 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/05 22:14:31 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(d_list *a)
{
	unsigned int	mistakes;
	unsigned int	total_pairs;
	unsigned int	i;
	unsigned int	j;	

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	j = 1;
	while (i++ < (sizeof(a->value)-1)) 
	{
		while (j++ < (sizeof(a->value) - 1))
		{
			++total_pairs;
			if (a->value[i] > a->value[j])
				++mistakes;
		}
	}
	return ((double)(mistakes/total_pairs));
}
