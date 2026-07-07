#include "push_swap.h"

// PA: take the first element from the top of B and place it at the top of A.
// Do nothing if B is empty.
void	op_pa(t_dlist **stack_a, t_dlist **stack_b, t_state *state)
{
	t_dlist	*tmp;

	if (!stack_a || !stack_b || !state)
		return ;
	if (!(*stack_b))
		return ;
	tmp = lst_release_front(state, stack_b, &state->tail_b);
	if (!tmp)
		return ;
	lst_add_front(state, tmp, stack_a, &state->tail_a);
}