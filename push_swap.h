#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

typedef struct sd_list
{
	int				value;
	struct s_d_list	*next;
	struct s_d_list	*prev;
}	td_list;


#endif
