/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 23:10:07 by sashin            #+#    #+#             */
/*   Updated: 2020/10/22 01:24:22 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_gogo(int num, int digc, int n, char comb[])
{
	if (digc == n)
	{
		write(1, comb, n);
		if (!(comb[0] == (10 - n) + 48))
			write(1, ", ", 2);
	}
	while (num < 10)
	{
		comb[digc] = num + 48;
		ft_gogo(num + 1, digc + 1, n, comb);
		++num;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];

	if (n <= 0 || n >= 10)
		return ;
	ft_gogo(0, 0, n, comb);
}
