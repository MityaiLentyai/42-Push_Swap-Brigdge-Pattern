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

// void delete_state(t_state state);
