/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:47:34 by sashin            #+#    #+#             */
/*   Updated: 2020/11/03 12:12:59 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


int			ft_is_space()

int			ft_is_nbr_correct(char *nbr, char *base_from, int *sign)
{
	int		i;

	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		++i;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			*sign = (*sign) * (-1);
		++i;
	}
	while (ft_is_base() == 1)
	{
		
	}

}


int			ft_is_base_correct(char *base)
{
	int		i;
	int		j;
	int		length;

	i = 0;
	while (base[i] || )
		++i;
	length = i;
	if (length <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13) ||
				base[i] == '+' || base[i] == '-')
				return (0);
	}
	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}



char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		bflength;

	bflength = 0;
	while (base_from[bflength])
		++bflength;
	


	}
}
