#include "push_swap.h"

size_t	check_flags(int argc, char **argv, t_state state)
{
	if (ft_strcmp)

}
// 0 means success, 1 means failure
int	parse_input(int argc, char **argv, t_state state)
{
	size_t	i;
	char	*input;
	t_list	stack_a;

	i = check_flags(argc, argv, state);

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
