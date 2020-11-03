CFLAGS = -Wall -Wextra -Werror
NAME = rush-02
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
