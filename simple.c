#include "push_swap.h"

// I suggest selection sort for small stacks as i showed you on Saturday.
// If you want some other algorithm let me know which.
// Selection sort seems the easiest to me.

void	simple(t_state *state)
{
	int	stack_size;
	int	min_idx;

        while (state->stack_a->head)
        {
                printf("%d\n", state->stack_a->head->value);
                state->stack_a->head = state->stack_a->head->next;
        }
        stack_size = list_size(state->stack_a->head);
	while (stack_size > 2)
	{
		min_idx = idx_of_min(state->stack_a->head);
		if (min_idx > (stack_size - 1) / 2)
			rra(state, stack_size - min_idx);
		else
			ra(state, min_idx);
		pa(state, 1);
		stack_size--;
	}
	// if (check_if_swap(state->stack_a->head))
	// 	sa(state, 1);
	stack_size = list_size(state->stack_b->head);
	pa(state, stack_size);
}
