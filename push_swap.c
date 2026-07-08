#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_state	*state;

	if (argc < 2)
		return (0);
	else
	{
		state = create_state();
		if (!state || parse_input(argc, argv, state))
		{
			// Handle error in parsing input
			return (1);
		}
	}
	while (state->head_a)
	{
		printf("%d\n", state->head_a->value);
		state->head_a = state->head_a->next;
	}
	free_state(&state);
	return (0);
}
