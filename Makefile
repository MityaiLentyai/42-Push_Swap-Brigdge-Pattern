NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -O0
RM = rm -f

SRCS = push_swap.c parser_1.c parser_2.c struct_state.c struct_benchmark_1.c  \
struct_benchmark_2.c medium_1.c medium_2.c put_count_op_1.c put_count_op_2.c \
list_operations_1.c list_operations_2.c help_search_func.c simple.c \
complex_1.c complex_2.c small_stack_case.c disorder.c \
stack_operations_1.c stack_operations_2.c stack_operations_3.c \
put_count_op_3.c

OBJS = $(SRCS:.c=.o)
DEBUG_OBJS = $(SRCS:.c=.debug.o)
BONUS_SRCS = $(filter-out push_swap.c,$(SRCS)) checker.c get_next_line.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
LIBFT = libft/libft.a
BONUS = checker

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
	@ $(RM) $(OBJS) $(DEBUG_OBJS) $(BONUS_OBJS)
	@ $(MAKE) -C libft clean

fclean: clean
	@ $(RM) $(NAME) $(NAME)_debug $(BONUS)
	@ $(MAKE) -C libft fclean

re: fclean all

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)

.PHONY: all clean fclean re bonus
