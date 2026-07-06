/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuszano <nsuszano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:13:18 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/05 11:28:36 by nsuszano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	counter;
	int		word;

	counter = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			word = 1;
			counter++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (counter);
}

static void	free_array(char **array, size_t idx)
{
	size_t	curr_idx;

	curr_idx = 0;
	while (curr_idx < idx)
	{
		free(array[curr_idx]);
		curr_idx++;
	}
	free(array);
}

static int	fill(char **array, size_t counter, char c, char const *s)
{
	size_t		which_word;
	char const	*start;
	char const	*end;

	which_word = 0;
	end = s;
	while (which_word < counter)
	{
		while (*end && *end == c)
			end++;
		start = end;
		while (*end && *end != c)
			end++;
		array[which_word] = ft_substr(start, 0, end - start);
		if (!array[which_word])
		{
			free_array(array, which_word);
			return (0);
		}
		which_word++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**array;
	size_t		counter;

	if (!s)
		return (NULL);
	counter = count_words(s, c);
	array = ft_calloc(counter + 1, sizeof(char *));
	if (!array)
		return (NULL);
	if (!fill(array, counter, c, s))
		return (NULL);
	return (array);
}

// int	main(void)
// {
// 	char	s[] = "pierwsze, drugie, zmien,, obuwie";
// 	char	**array = ft_split(s, ',');
// 	int	i = 0;
// 	while(array[i])
// 	{
// 		printf("%s\n", array[i]);
// 		free(array[i]);
// 		i++;
// 	}
// 	i = 0;
// 	free(array);
// }