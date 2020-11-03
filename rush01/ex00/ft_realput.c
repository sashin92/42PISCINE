/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:46:39 by sashin            #+#    #+#             */
/*   Updated: 2020/10/25 18:27:25 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		ft_comparerow(char **arr, int row, int index);
char		ft_comparecol(char **arr, int col, int index);
char		ft_comparerowdown(char **arr, int row, int index);
char		ft_comparecolright(char **arr, int col, int index);
int			ft_realput(char **arr, int col, int row, int num);
int			ft_putnum(char **arr, char **input, int arrloc);

int			ft_realput(char **arr, int col, int row, int num)
{
	int		i;

	i = 0;
	if (num <= 4)
	{
		arr[col][row] = '0' + num;
		while (i < row)
		{
			if (i == row)
				++i;
			else if (arr[col][i] == arr[col][row])
			{
				++num;
				arr[col][row] = '0' + num;
				i = 0;
			}
			else
				++i;
		}
		i = 0;
		while (i < col)
		{
			if (i == col)
				++i;
			else if (arr[i][row] == arr[col][row])
			{
				++num;
				arr[col][row] = '0' + num;
				i = 0;
			}
			else
				++i;
		}
	}
	return (num);
}
