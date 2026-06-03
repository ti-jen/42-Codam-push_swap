CC = gcc
NAME = libft
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi\
ft_bzero\
ft_calloc\
ft_isalnum\
ft_isalpha\
ft_isascii\
ft_isdigit\
ft_isprint\
ft_itoa\
ft_lstadd_back\
ft_lstadd_front\
ft_lstclear\
ft_lstdelone\
ft_lstiter\
ft_lstlast\
ft_lstmap\
ft_lstnew\
ft_lstsize\
ft_memchr\
ft_memcmp\
ft_memcpy\
ft_memmove\
ft_memset\
ft_putchar_fd\
ft_putnbr_fd\
ft_putstr_fd\
ft_split\
ft_strchr\
ft_strdup\
ft_striteri\
ft_strjoin\
ft_strlcat\
ft_strlcpy\
ft_strlen\
ft_strmapi\
ft_strncmp\
ft_strnstr\
ft_strrchr\
ft_strtrim\
ft_substr\
ft_tolower\
ft_toupper\


SRCS = $(addsuffix .c, $(SRC))
OBJ	= $(addsuffix .o, $(SRC))

all: ar

# final: lib
# 	$(CC) $(CFLAGS) $(NAME).c -L. $(NAME).a


ar: comp
	ar rcs $(NAME).a $(OBJ)

comp:
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm $(OBJ) || true

fclean: clean
	rm $(NAME).a || true

re: fclean all