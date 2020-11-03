/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:06:50 by sashin            #+#    #+#             */
/*   Updated: 2020/10/26 23:43:15 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		write(1, (str + i), 1);
		++i;
	}
}

void	ft_putnbr(int nb)
{
	char num;

	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putstr("-");
		nb = nb * (-1);
	}
	num = nb % 10 + '0';
	if (nb >= 10)
	{
		nb = nb / 10;
		ft_putnbr(nb);
	}
	write(1, &num, 1);
}
