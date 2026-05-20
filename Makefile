CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
VALGRIND = valgrind -q --leak-check=full
SRC = 	ft_cleanlist\
		ft_lstprint\
		ft_make_lst\
		ft_print_bench\
		ft_sort_bubble\
		ft_sort_bucket\
		ft_sort_radix\
		ft_sort_selection\
		func_lst\
		func_sort_bubble\
		func_sort_bubble2\
		func_sort_selection\
		op_push\
		op_reverse_rotate\
		op_rotate\
		op_swap

SRCS = $(addsuffix .c, $(SRC))
OBJ	= $(addsuffix .o, $(SRC))
INPUT = 2 4 1 5 3
YELLOW  = \033[0;33m
GREEN = \033[0;32m
WHITE = \033[0m
all: lib
	@$(CC) $(CFLAGS) main.c -o push_swap -L. $(NAME).a libft/libft.a libft/ft_printf/libftprintf.a

# test: lib 
# 	@echo "$(GREEN)Test output:$(WHITE)"
# 	@$(CC) $(CFLAGS) main.c -o push_swap -L. $(NAME).a libft/libft.a libft/ft_printf/libftprintf.a && ./push_swap --bench --simple $(INPUT) && make fclean

lib: comp ft_lib
	@ar rcs $(NAME).a $(OBJ)
	@echo "$(YELLOW)[compiling push_swap]$(WHITE)"

comp: 
	@$(CC) $(CFLAGS) -c $(SRCS)

ft_lib:
	@cd libft/ && make all
	@echo "$(YELLOW)[compiling libft]$(WHITE)"
	@cd libft/ft_printf/ && make all
	@echo "$(YELLOW)[compiling ft_printf]$(WHITE)"

clean:
	@rm $(OBJ) || true
	@cd libft/ && make clean
	@cd libft/ft_printf/ && make clean
	@echo "$(CYAN)[removing $(OBJ)]$(WHITE)"

fclean: clean
	@rm $(NAME).a || true
	@cd libft/ && make fclean
	@cd libft/ft_printf/ && make fclean
	@echo "$(CYAN)[removing $(NAME).a]$(WHITE)"

re: fclean all