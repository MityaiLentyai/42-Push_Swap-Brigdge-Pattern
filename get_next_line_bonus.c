/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:44:23 by nsuszano          #+#    #+#             */
/*   Updated: 2026/07/21 15:22:24 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "libft/libft.h"

size_t	count_line_size(char *content)
{
	size_t	size;

	size = 0;
	if (!content)
		return (size);
	while (content[size] && content[size] != '\n')
		size++;
	if (content[size] == '\n')
		size++;
	return (size);
}

char	*get_first_line(char *content, size_t first_line_size)
{
	char	*first_line;

	first_line = ft_substr(content, 0, first_line_size);
	return (first_line);
}

char	*remove_first_line(char *content, size_t first_line_size)
{
	char	*trimmed_content;
	size_t	length;

	length = ft_strlen(content) - first_line_size;
	trimmed_content = ft_substr(content, first_line_size, length);
	free(content);
	return (trimmed_content);
}

char	*read_buffor(char *content, int fd)
{
	int		how_many_read;
	char	*input;
	char	*to_return;

	input = malloc((BUFFOR_SIZE + 1) * sizeof(char));
	if (!input)
		return (NULL);
	how_many_read = 1;
	while (how_many_read > 0)
	{
		if (ft_strchr(content, '\n'))
			break ;
		how_many_read = read(fd, input, BUFFOR_SIZE);
		if (how_many_read < 0)
		{
			free(input);
			return (content);
		}
		input[how_many_read] = '\0';
		to_return = ft_strjoin(content, input);
		free(content);
		content = to_return;
	}
	free(input);
	return (content);
}

char	*get_next_line(int fd)
{
	size_t		first_line_size;
	char		*curr_line;
	static char	*content;

	if (fd < 0 || BUFFOR_SIZE <= 0)
		content = NULL;
	else
		content = read_buffor(content, fd);
	if (!content || !*content)
	{
		free(content);
		content = NULL;
		return (NULL);
	}
	first_line_size = count_line_size(content);
	curr_line = get_first_line(content, first_line_size);
	content = remove_first_line(content, first_line_size);
	return (curr_line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	setvbuf(stdout, NULL, _IONBF, 0); // wylacza buforowanie
// 	fd = open("text.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	while (*s)
// 	{
// 		printf("%s", s);
// 		free(s);
// 		s = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
