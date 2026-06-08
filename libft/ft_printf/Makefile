CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRC = ft_putchar \
ft_printf\
ft_strpint\
ft_putstr\
ft_putadres\
ft_putdec\
ft_putudec\
ft_puthexlow\
ft_puthexhigh\
ft_itoa\
ft_strlcpy\

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# test: lib
# 	$(CC) $(CFLAGS) test.c -L. $(NAME).a

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	echo "$(YELLOW)[compiling push_swap]$(WHITE)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all
