CC = cc
NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
VALGRIND = valgrind -q --leak-check=full
SRC = 	ft_cleanlist\
		ft_make_lst\
		ft_print_bench\
		ft_sort_bubble\
		ft_sort_bucket\
		ft_sort_selection\
		func_lst\
		func_sort_bubble\
		func_sort_bubble2\
		func_sort_selection\
		op_push\
		op_reverse_rotate\
		op_rotate\
		op_swap\
		ft_sort_quick


SRCS = $(addsuffix .c, $(SRC))
OBJS = $(SRCS:.c=.o)

all: $(EXEC_FILE)

$(EXEC_FILE): $(NAME) libft/libft.a libft/ft_printf/libftprintf.a
	$(CC) $(CFLAGS) main.c -o push_swap -L. $(NAME) libft/libft.a libft/ft_printf/libftprintf.a

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a: libft
	cd libft/ && $(MAKE)

libft/ft_printf/libftprintf.a: libftprintf
	cd libft/ft_printf/ && $(MAKE)

clean:
	rm -f $(OBJS)
	cd libft/ && make clean
	cd libft/ft_printf/ && make clean

fclean: clean
	rm -f $(NAME)
	cd libft/ && make fclean
	cd libft/ft_printf/ && make fclean

re: fclean all

.PHONY: all clean fclean re libft libftprintf