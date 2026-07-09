#include "push_swap.h"

int main(int argc, char **argv)
{
	t_state	*state;
	t_dlist	*current;

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
	current = state->stack_a->head;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	simple(state);
	printf("After:\n");
	current = state->stack_a->head;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	free_state(&state);
	return (0);
}
