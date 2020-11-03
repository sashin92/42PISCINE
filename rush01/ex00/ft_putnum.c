/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 11:12:19 by sashin            #+#    #+#             */
/*   Updated: 2020/10/25 18:27:02 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		ft_comparerow(char **arr, int row, int index);
char		ft_comparecol(char **arr, int col, int index);
int			ft_realput(char **arr, int col, int row, int num);

int			ft_putnum(char **arr, char **input, int arrloc)
{
	int		i;
	int		col;
	int		row;
	int		num;

	col = arrloc % 4;
	row = arrloc / 4;
	i = 0;
	num = 1;
	if (arrloc == 16)
		return (0);
	while (num <= 4)
	{
		num = ft_realput(arr, col, row, num);
		ft_realput(arr, col, row, num);
		if (input[2][row] >= ft_comparerow(arr, row, 0) && input[0][col] >= ft_comparecol(arr, col, 0))
		{
			++arrloc;
			ft_putnum(arr, input, arrloc);
			if (!(arr[3][3] == 0))
				return (0);
		}
		++num;
	}
	arr[col][row] = '0';
	return (0);
}
