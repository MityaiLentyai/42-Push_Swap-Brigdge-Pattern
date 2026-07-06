#include "push_swap.h"

// I suggest selection sort for small stacks as i showed you on Saturday.
// If you want some other algorithm let me know which.
// Selection sort seems the easiest to me.

void	simple(t_state *state)
{
	int	stack_a_size;
	int	min_idx;
	int how_many_op;

	stack_a_size = list_size(state->stack_a);
	while (stack_a_size > 2)
	{
		min_idx = idx_of_min(state->stack_a);
		if (min_idx > (stack_a_size - 1) / 2)
			RRA(state, stack_a_size - min_idx);
		else
			RA(state, min_idx);
		PA(state, 1);
		stack_a_size--;
	}
	if (check_if_swap(state->stack_a))
		SA(state, 1);
	stack_a_size =
}
