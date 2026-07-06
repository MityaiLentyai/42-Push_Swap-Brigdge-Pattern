NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = push_swap.c parser.c struct_state.c struct_benchmark.c \
list_operations.c help_search_func.c simple.c medium.c \
complex.c adaptive.c disorder.c output.c small_stack_case.c \
test.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re