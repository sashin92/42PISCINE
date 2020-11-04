#!/bin/sh

gcc -Wall -Werror -Wextra -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar crvs libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
rm ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o