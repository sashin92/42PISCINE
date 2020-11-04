CC = gcc
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = crvs
SOURCES_DIR = ./srcs/
SOURCES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
HEADER_DIR = ./includes/
HEADER = ft.h
OBJECT = $(SOURCES:.c=.o)



all: $(NAME)
	$(AR) $(ARFLAGS) $@ $(addprefix $(HEADER_DIR), )


$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) -c $(addprefix $(SOURCES_DIR), SOURCES)



clean:
	rm $(OBJECT)

fclean: clean
	rm $(NAME)

re:
	