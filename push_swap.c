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
	printf("Before:\n");
	while (state->stack_a->head)
	{
		printf("%d\n", state->stack_a->head->value);
		state->stack_a->head = state->stack_a->head->next;
	}
	simple(state);
	printf("After:\n");
	while (state->stack_a->head)
	{
		printf("%d\n", state->stack_a->head->value);
		state->stack_a->head = state->stack_a->head->next;
	}
	free_state(&state);
	return (0);
}
