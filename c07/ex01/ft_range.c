/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:30:26 by sashin            #+#    #+#             */
/*   Updated: 2020/11/02 14:50:03 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*val;
	int		num_range;
	int		i;

	i = 0;
	num_range = max - min;
	if (max <= min)
	{
		val = NULL;
		return (val);
	}
	else
	{
		val = (int*)malloc(sizeof(int) * num_range);
		while (i < num_range)
		{
			val[i] = min + i;
			++i;
		}
	}
	return (val);
}
