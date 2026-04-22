CC = gcc
NAME = libftprintf
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
OBJ	= $(addsuffix .o, $(SRC))


all: lib

# test: lib
# 	$(CC) $(CFLAGS) test.c -L. $(NAME).a

lib: comp 
	ar rcs $(NAME).a $(OBJ)

comp: 
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm $(OBJ) || true

fclean: clean
	rm $(NAME).a || true

re: fclean all
