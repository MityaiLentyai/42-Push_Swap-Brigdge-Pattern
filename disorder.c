/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:05:13 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/05 15:44:00 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//function compute_disorder(stack a):
//	mistakes = 0
//	total_pairs = 0
//	for i from 0 to size(a)-1:
//		for j from i+1 to size(a)-1:
//			total_pairs += 1
//			if a[i] > a[j]:
//				mistakes += 1
//	return mistakes / total_pairs

// This is a mockup of a disorder function. To finish it properly we need
// a concrete idea of what type and how we are gonna store "STACK A" in


double	compute_disorder(stack a)
{
	unsigned int	mistakes;
	unsigned int	total_pairs;
	unsigned int	i;
	unsigned int	j;	

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	j = 1;
	while (i++ < (sizeof(a.value)-1)) // Signature of a??? Need to discuss this
	{
		while (j++ < (sizeof(a.value) - 1)) // Signature of a???
		{
			++total_pairs;
			if (a.value[i] > a.value[j])
				++mistakes;
		}
	}
	return ((double)(mistakes/total_pairs));
}
