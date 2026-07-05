#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

// Enum to mark the algorithm type we are supposed to use.
// We can use either enum or normal struck with int variable to mark the algorithm type.
// But enum seems more appropriate, since it keep one current value - easy to check if
// the algorithm type is already set
typedef enum e_algorithm
{
	NOT_SET,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_algorithm;

// BENCHMARK - I suggest to use int/bool variable to mark if we have to print benchmark or not.
// But we can also make struct for it, if it seems more consequent.
// IDK what is "better programming practice" - let me know, what you think about it.

// For now, i am starting to implement null-eneded double linked list,
// but, in case, it will not take much to modify basic list operations to circular one.

typedef struct list
{
	int	value;
	struct list	*next;
	struct list	*prev;
}	d_list;

// I suppose it will be easier if we use struct with current state of stacks etc
// this way we can pass it as one argument to functions; sth like belowe

typedef struct s_state
{
	d_list	*stack_a;
	d_list	*stack_b;
	t_algorithm	algorithm;
	t_benchmark	*benchmark;
}	t_state;

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

int			parse_input(int argc, char **argv, t_state state);
size_t		check_algorithm(char **argv, t_state state);
t_state		*create_state();
t_benchmark	*create_benchmark();



#endif
