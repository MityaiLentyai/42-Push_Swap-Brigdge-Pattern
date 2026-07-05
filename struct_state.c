#include "push_swap.h"

t_state	*create_state()
{
    t_state	*state;
    t_list  *stack_a;

    state = malloc(sizeof(t_state));
    if (!state)
        return (NULL);
    state->stack_a = NULL;
    state->stack_b = NULL;
    state->algorithm = NOT_SET;
    state->benchmark = creat_benchmark();
    return (state);
}

// void delete_state(t_state state);
