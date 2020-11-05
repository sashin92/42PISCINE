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
	

$(NAME): $(OBJECT)
	$(AR) $(ARFLAGS) $@ $(addprefix $(HEADER_DIR), $(HEADER))

$(OBJECT): $(SROUCES)
	$(CC) $(CFLAGS) -c $(addprefix $(SOURCES_DIR), $(SOURCES)) -I$(addprefix $(HEADER_DIR), $(HEADER))


clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all
-------------------------------------------------------------------------------------

all: $(TARGET)
clean:
	rm -rf $(OBJS)
fclean:
	rm -rf $(OBJS) $(TARGET)
re:	fclean all
$(TARGET) : $(addprefix $(HEADER_DIR)/, $(HEADER)) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@ -I$(HEADER_DIR)