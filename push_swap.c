#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
	{
		state = create_state();
		if (parse_input(argc, argv, state))
		{
			// Handle error in parsing input
		}

	}
}
