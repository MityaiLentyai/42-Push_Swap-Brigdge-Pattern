#include "push_swap.h"

size_t	check_algorithm(char **argv, t_state state)
{
	if (ft_strncmp("--simple", argv[1], ft_len(argv[1])) == 0)
	{
		if (state->algorithm != NON_SET)
			return (1);
		state->algorithm = SIMPLE;
	}
	else if (ft_strncmp("--medium", argv[1], ft_len(argv[1])) == 0)
	{
		if (state->algorithm != NON_SET)
			return (1);
		state->algorithm = MEDIUM;
	}
	else if (ft_strncmp("--complex", argv[1], ft_len(argv[1])) == 0)
	{
		if (state->algorithm != NON_SET)
			return (1);
		state->algorithm = COMPLEX;
	}
	else if (ft_strncmp("--adaptive", argv[1], ft_len(argv[1])) == 0)
	{
		if (state->algorithm != NON_SET)
			return (1);
		state->algorithm = ADAPTIVE;
	}
	return (0);
}
// 0 means success, 1 means failure
int	parse_input(int argc, char **argv, t_state state)
{
	size_t	i;
	char	*input;

	state = create_state();
	if (check_algorithm(argv, state))
		return (1);
	if ()

	while (i < argc)
	{
		input = argv[i];
		if(!input)
		{
			//ERROR
			return (1);
		}


		i++;
	}
}
