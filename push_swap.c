#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
	{
		d_list	**stack_a;
		d_list	**stack_b;
		stack_a = NULL;
		stack_b = NULL;
		if (parse_input(argc, argv, stack_a, stack_b))
		{
			// Handle error in parsing input
		}

	}
}
