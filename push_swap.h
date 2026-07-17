/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:30:31 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/16 14:02:35 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

// Enum to mark the algorithm type we are supposed to use.
// We can use either enum or normal struck with int
// variable to mark the algorithm type.
// But enum seems more appropriate, since it keep
// one current value - easy to check if
// the algorithm type is already set
typedef enum e_algorithm
{
	NOT_SET,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_algorithm;

// BENCHMARK - I suggest to use int/bool variable to mark if we have to print
// benchmark or not.
// But we can also make struct for it, if it seems more consequent.
// IDK what is "better programming practice" - LMK, what you think about it.

// For now, i am starting to implement null-eneded double linked list,
// but, in case, it will not take much to modify basic
// list operations to circular one.

typedef struct list
{
	int			value;
	struct list	*next;
	struct list	*prev;
}	t_dlist;

// to_print = 1 if we are supposed to print it; 0 otherwise
// the rest is to follow how many of each operation we have already used
typedef struct s_benchmark
{
	size_t	to_print;
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}	t_benchmark;

// I suppose it will be easier if we use struct with current state of stacks etc
// this way we can pass it as one argument to functions; sth like belowe

typedef struct s_stack
{
	t_dlist	*head;
	t_dlist	*tail;
}	t_stack;

typedef struct s_state
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_algorithm	algorithm;
	t_benchmark	*benchmark;
	double		disorder;
}	t_state;

double		compute_disorder(t_stack *stack);
int			parse_input(int argc, char **argv, t_state *state);
size_t		check_algorithm(char **argv, t_state *state);
size_t		check_duplicates(t_dlist *stack, int input_value);
t_state		*create_state(void);
t_benchmark	*create_benchmark(void);

t_dlist		*create_node(int value);
void		free_state(t_state **state);

void		free_benchmark(t_benchmark **benchmark);

void		simple(t_state *state);

void		free_dlist(t_dlist **head, t_dlist **tail);
void		lst_add_back(t_dlist *new, t_dlist **head, t_dlist **tail);
void		lst_add_front(t_dlist *new, t_dlist **head, t_dlist **tail);
t_dlist		*lst_release_front(t_dlist **head, t_dlist **tail);
t_dlist		*lst_release_back(t_dlist **head, t_dlist **tail);
int			idx_of_min(t_dlist *stack);
size_t		list_size(t_dlist *head);
int			check_if_swap(t_dlist *head);
void		swap_two_first(t_dlist **head, t_dlist **tail);
void		call_benchmark(t_state *state);

void		pa(t_state *state, int counter);
void		pb(t_state *state, int counter);
void		ra(t_state *state, int counter);
void		rb(t_state *state, int counter);
void		rr(t_state *state, int counter);
void		sa(t_state *state);
void		sb(t_state *state);
void		ss(t_state *state);
void		rra(t_state *state, int counter);
void		rrb(t_state *state, int counter);
void		rrr(t_state *state, int counter);

#endif
