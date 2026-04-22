CC = gcc
NAME = libft
CFLAGS = -Wall -Wextra -Werror
SRC = ft_*

all: ar

# final: lib
# 	$(CC) $(CFLAGS) $(NAME).c -L. $(NAME).a


ar: comp
	ar rcs $(NAME).a $(SRC).o

comp:
	$(CC) $(CFLAGS) -c $(SRC).c

clean:
	rm $(SRC).o || true

fclean: clean
	rm $(NAME).a || true

re: fclean all