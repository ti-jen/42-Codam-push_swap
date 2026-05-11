CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
VALGRIND = valgrind -q --leak-check=full
SRC = op_push\
op_rotate\
op_reverse_rotate\
op_swap\
ft_lstprint\
ft_make_lst\
ft_print_bench\
ft_bucket_sort\
lst_functions\

SRCS = $(addsuffix .c, $(SRC))
OBJ	= $(addsuffix .o, $(SRC))
INPUT = 1 2 3 4 5 6 7  9 10 -100 -50 0 9999
YELLOW  = \033[0;33m
GREEN = \033[0;32m
WHITE = \033[0m
all: ar

test: lib 
	@echo "$(GREEN)Test output:$(WHITE)"
	@$(CC) $(CFLAGS) main.c -o push_swap -L. $(NAME).a libft/libft.a libft/ft_printf/libftprintf.a && ./push_swap --bench --medium $(INPUT) && make fclean

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
	@echo "$(CYAN)[removing $(OBJ)]$(WHITE)"

fclean: clean
	@rm $(NAME).a || true
	@echo "$(CYAN)[removing $(NAME).a]$(WHITE)"

re: fclean all