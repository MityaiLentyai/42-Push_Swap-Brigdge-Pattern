#include "push_swap.h"

t_state	*create_state()
{
    t_state	*state;

    state = malloc(sizeof(t_state));
    if (!state)
        return (NULL);
    state->head_a = NULL;
    state->head_b = NULL;
    state->algorithm = NOT_SET;
    state->benchmark = create_benchmark();
    state->tail_a = NULL;
    state->tail_b = NULL;
    return (state);
}

void free_state(t_state **state)
{
    if (!state || !*state)
        return ;
    free_dlist(&(*state)->head_a, &(*state)->tail_a);
    free_dlist(&(*state)->head_b, &(*state)->tail_b);
    free_benchmark(&(*state)->benchmark);
    free(*state);
    *state = NULL;
}
