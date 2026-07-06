#include "push_swap.h"


// 1 means duplicate found --> ERROR; 0 means everything fine
size_t	check_duplicates(d_list	*stack, int input_value)
{
	while (stack)
	{
		if (stack->value == input_value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

size_t	check_algorithm(char **argv, t_state *state)
{
	if (ft_strncmp("--simple", argv[1], ft_len(argv[1])) == 0)
	{
		if (state->algorithm != NOT_SET)
			return (1);
		state->algorithm = SIMPLE;
	}
	else if (ft_strncmp("--medium", argv[1], ft_len(argv[1])) == 0)
	{
		if (state->algorithm != NOT_SET)
			return (1);
		state->algorithm = MEDIUM;
	}
	else if (ft_strncmp("--complex", argv[1], ft_len(argv[1])) == 0)
	{
		if (state->algorithm != NOT_SET)
			return (1);
		state->algorithm = COMPLEX;
	}
	else if (ft_strncmp("--adaptive", argv[1], ft_len(argv[1])) == 0)
	{
		if (state->algorithm != NOT_SET)
			return (1);
		state->algorithm = ADAPTIVE;
	}
	return (0);
}
// 0 means success, 1 means failure
int	parse_input(int argc, char **argv, t_state *state)
{
	size_t	i;
	int	input_value;
	d_list	*curr_node;

	i = 1;
	state = create_state();
	if (check_algorithm(argv, state))
		return (1);
	if (state->algorithm == NOT_SET)
		state->algorithm = ADAPTIVE;
	else
		i++;
	if (i >= argc)
		return (1);
	if (ft_strncmp("--bench", argv[i], ft_len(argv[i])) == 0)
	{
		state->benchmark->to_print = 1;
		i++;
	}
	while (i < argc)
	{
		input_value = ft_atoi(argv[i]) // change atoi so it wouldnt accept input like 25cds
		if(!input || check_duplicates(state->stack_a, input_value))
		{
			//ERROR
			return (1);
		}
		curr_node = create_node(input_value);
		if (!curr_node)
		{
			free_stack(state->stack_a);
			// ERROR
			return (1);
		}
		lst_add_back(state->stack_a, curr_node);
		i++;
	}
	return (0);
}
