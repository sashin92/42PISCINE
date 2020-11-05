CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
AR = ar
ARFLAGS = crv
TARGET = libft.a
HEADER_DIR =./includes
HEADER = ft.h
SRC_DIR = ./srcs
SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@ -I$(HEADER_DIR)

all: $(TARGET)

$(TARGET) : $(addprefix $(HEADER_DIR)/, $(HEADER)) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re:	fclean all