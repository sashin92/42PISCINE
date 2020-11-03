/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:51:47 by sashin            #+#    #+#             */
/*   Updated: 2020/11/02 19:38:04 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		*val;
	int		num_range;
	int		i;

	i = 0;
	if (max <= min)
	{
		val = NULL;
		range[0] = val;
		return (0);
	}
	num_range = max - min;
	val = (int*)malloc(sizeof(int) * num_range);
	if (val == NULL)
		return (-1);
	while (i < num_range)
	{
		val[i] = min + i;
		++i;
	}
	range[0] = val;
	return (num_range);
}
