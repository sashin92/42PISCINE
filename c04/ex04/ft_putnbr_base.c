/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:53:44 by sashin            #+#    #+#             */
/*   Updated: 2020/10/29 17:40:21 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_check(char *base, int length)
{
	int		i;
	int		j;

	i = 0;
	while (*(base + i))
	{
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r' || base[i] == ' '
			|| base[i] == '+' || base[i] == '-')
			return (1);
		++i;
	}
	i = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (*(base + i) == *(base + j))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

void		ft_putnbr(int nbr, char *base, int length)
{
	char num;

	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			num = base[-(nbr % length)];
			ft_putnbr(-(nbr / length), base, length);
			write(1, &num, sizeof(char));
			return ;
		}
		nbr = nbr * (-1);
	}
	num = base[nbr % length];
	if (nbr >= length)
	{
		nbr = nbr / length;
		ft_putnbr(nbr, base, length);
	}
	write(1, &num, sizeof(char));
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		length;

	length = 0;
	while (*(base + length))
		++length;
	if (length <= 1)
		return ;
	if (ft_check(base, length) == 1)
		return ;
	ft_putnbr(nbr, base, length);
}
