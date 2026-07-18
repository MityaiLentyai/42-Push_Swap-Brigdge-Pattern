NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -O0
RM = rm -f

SRCS = push_swap.c parser.c struct_state.c struct_benchmark.c \
list_operations_1.c list_operations_2.c help_search_func.c simple.c \
complex.c adaptive.c output.c small_stack_case.c disorder.c \
test.c stack_operations_1.c stack_operations_2.c stack_operations_3.c \
medium.c

OBJS = $(SRCS:.c=.o)
DEBUG_OBJS = $(SRCS:.c=.debug.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

debug: $(NAME)_debug

$(NAME)_debug: $(DEBUG_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(DEBUG_OBJS) $(LIBFT) -o $(NAME)_debug

%.debug.o: %.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

$(LIBFT):
	@ $(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJS) $(DEBUG_OBJS)
	@ $(MAKE) -C libft clean

fclean: clean
	@ $(RM) $(NAME) $(NAME)_debug
	@ $(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
