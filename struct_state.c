#include "push_swap.h"

t_stack *create_stack()
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->head = NULL;
    stack->tail = NULL;
    return (stack);
}

t_state	*create_state()
{
    t_state	*state;

    state = malloc(sizeof(t_state));
    if (!state)
        return (NULL);
    state->stack_a = create_stack();
    state->stack_b = create_stack();
    state->algorithm = NOT_SET;
    state->benchmark = create_benchmark();
    return (state);
}

void    free_stack(t_stack  **stack)
{
    if (!stack || !*stack)
        return ;
    free_dlist(&(*stack)->head, &(*stack)->tail);
    free(*stack);
    return ;
}

void    free_state(t_state **state)
{
    if (!state || !*state)
        return ;
    free_stack(&(*state)->stack_a);
    free_stack(&(*state)->stack_b);
    free_benchmark(&(*state)->benchmark);
    free(*state);
    *state = NULL;
}
