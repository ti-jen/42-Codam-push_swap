# Compile and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror


# Variable for setting name of the libary we want to create
NAME = libft.a

# Sourcefiles and defered objects = compiled files
SRCS =  ft_bzero.c\
        ft_isascii.c\
		ft_memcpy.c\
		ft_strlen.c\
		ft_isalnum.c\
		ft_isdigit.c\
		ft_memset.c\
		ft_isalpha.c\
		ft_isprint.c\
		ft_strlcpy.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strlcat.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strnstr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c



OBJS = $(SRCS:.c=.o) # derived objects get name of c-source with .o extion

# Target: Prerequisites
# Default target
all: $(NAME)

# Work from the end product to the start
# For the step of creating he library it is first necessary all derived object are created
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile each .c file into a .o -> For objects to br made c-files are needed.
%.o: %.c

	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re