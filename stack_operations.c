#include "push_swap.h"

// PA: take the first element from the top of B and place it at the top of A.
// Do nothing if B is empty.
void	PA(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!counter || !state)
		return ;
	if (!(state->head_b)||(!(state->head_b)))
		return ;
	tmp = lst_release_front(state,&state->head_b , &state->tail_b);
	if (!tmp)
		return ;
	lst_add_front(state, tmp, &state->head_a, &state->tail_a);
}

// PB Take the first element at the top of a and put it ast the top of b.
// Do nothing if a is empty. 
void PB(t_state *state, int counter)
{
	t_dlist	*tmp;

	if (!counter || !state)
		return ;
	if (!(state->head_a)||(!(state->head_b)))
		return ;
	tmp = lst_release_front(state,&state->head_a , &state->tail_a);
	if (!tmp)
		return ;
	lst_add_front(state,tmp,&state->head_b,&state->tail_b);
}
// RA (rotate a): Shift up all elements of stack a by one.
// The first element becomes the last one. 
void RA(t_state *state, int counter)
{
        t_dlist *tmp;
        
        if (!counter || !state)
		return ;
	if (!(state->head_a)||(!(state->tail_a)))
		return ;
        tmp = lst_release_front(state,&state->head_a,&state->tail_a);
        if (!tmp)
                return  ;
        lst_add_back(state,tmp,&state->head_a,&state->tail_a); 
}

// RRA (reverse rotate a): Shift down all elements of stack a by one. 
// The last element becomes the first one.
void RRA(t_state *state, int counter)
{
        t_dlist *tmp;
        
        if (!counter || !state)
		return ;
	if (!(state->head_a)||(!(state->tail_a)))
		return ;
        tmp = lst_release_back(state,&state->head_a,&state->tail_a);
        if (!tmp)
                return  ;
        lst_add_front(state,tmp,&state->head_a,&state->tail_a); 
}
