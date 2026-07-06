#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_state	*state;

	if (argc < 2)
		return (0);
	else

		if (parse_input(argc, argv, state))
		{
			// Handle error in parsing input
			return (1);
		}
	}
	while (state->stack_a)
	{
		printf("%d\n", state->stack_a->value);
		state->stack_a = state->stack_a->next;
	}

	// free stacks
	return (0);
}
