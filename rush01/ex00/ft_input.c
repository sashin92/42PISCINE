/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 11:06:40 by sublee            #+#    #+#             */
/*   Updated: 2020/10/25 18:21:35 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char		*is_input_true(char *str);
int			ft_realput(char **arr, int col, int row, int num);
int			ft_putnum(char **arr, char **input, int arrloc);

char		**insert_input(char *str)
{
	int col;
	int row;
	static char **input;
	int i;

	input = malloc(sizeof(char *) * 4);
	i = 0;
	while (i < 4)
	{
		input[i] = malloc(sizeof(char) * 4);
		++i;
	}
	i = 0;
	col = 0;
	row = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			input[col][row] = str[i];
			col++;
			if (col == 4)
			{
				row++;
				col = 0;
			}
		}
		i++;
	}
	return (input);
}

char		**ft_input(char *str)
{
	int i;
	static char input[4][4];

	i = 0;
	if (is_input_true(str) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (insert_input(str));
}

char		*is_input_true(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
			{
				i++;
				count++;
			}
		}
		else if (str[i] == ' ')
			i++;
		else
			return (0);
	}
	if (count == 16)
		return (str);
	else
		return (0);
}

int			main(int argc, char **argv)
{
	int			i;
	int			j;
	char	**arr;
	char	**input;

	arr = malloc(sizeof(char *) * 4);
	i = 0;
	while (i < 4)
	{
		arr[i] = malloc(sizeof(char) * 4);
		++i;
	}
	input = ft_input(argv[1]);
	ft_putnum(arr, input, 0);
	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			write(1, &arr[j][i], 1);
			write(1, " ", 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}
