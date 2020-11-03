/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:47:14 by sashin            #+#    #+#             */
/*   Updated: 2020/11/03 01:05:45 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_itoc_and_print(int *q, int *count)
{
	int		i;
	char	cha_q;

	i = 0;
	while (i < 10)
	{
		cha_q = q[i] + '0';
		write(1, &cha_q, 1);
		++i;
	}
	write(1, "\n", 1);
	++*count;
}

int			ft_compare(int col, int row, int *q)
{
	int		i;
	int		abs_val;

	i = 0;
	while (i < col)
	{
		if (q[i] == row)
			return (0);
		if (q[i] - row < 0)
			abs_val = row - q[i];
		else if (q[i] - row >= 0)
			abs_val = q[i] - row;
		if (col - i == abs_val)
			return (0);
		++i;
	}
	return (1);
}

int			ft_backtrack_queen(int col, int *q, int *count)
{
	int		row;

	if (col == 10)
	{
		ft_itoc_and_print(q, count);
		return (0);
	}
	row = 0;
	while (row < 10)
	{
		if (ft_compare(col, row, q) == 1)
		{
			q[col] = row;
			ft_backtrack_queen(col + 1, q, count);
		}
		++row;
	}
	return (0);
}

int			ft_ten_queens_puzzle(void)
{
	int		q[10];
	int		count;

	count = 0;
	ft_backtrack_queen(0, q, &count);
	return (count);
}
