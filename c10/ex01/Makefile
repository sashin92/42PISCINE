CC = gcc
CFLAG = -Wall -Werror -Wextra
NAME = ft_cat
SRCS = main.c
OBJECTS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS)
	$(CC) $< -o $@

$(OBJECTS):
	$(CC) -c $(CFLAG) $(SRCS)

clean:
	rm -rf $(OBJECTS)

fclean:		clean
	rm -rf $(NAME)