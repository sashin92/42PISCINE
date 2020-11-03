/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:45:22 by sashin            #+#    #+#             */
/*   Updated: 2020/10/25 18:21:07 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_comparecol(char **arr, int col, int index)
{
	char	*countc;
	char	c;
	int		i;

	c = '1';
	countc = &c;
	i = 0;
	while (index + i <= 3)
	{
		if (arr[col][index] < arr[col][index + i])
		{
			++*countc;
			index = index + i;
			ft_comparecol(arr, col, index);
			break ;
		}
		++i;
	}
	return (*countc);
}

char	ft_comparerow(char **arr, int row, int index)
{
	char	*countr;
	char	c;
	int		i;

	c = '1';
	countr = &c;
	i = 0;
	while (index + i <= 3)
	{
		if (arr[index][row] < arr[index + i][row])
		{
			++*countr;
			index = index + i;
			ft_comparerow(arr, row, index);
			break ;
		}
		++i;
	}
	return (*countr);
}
