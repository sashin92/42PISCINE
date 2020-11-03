/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:52:47 by sashin            #+#    #+#             */
/*   Updated: 2020/10/22 01:57:59 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b);

int		main(void)
{
	int		a;
	int		b;
	char	result[2];

	a = 7;
	b = 3;
	ft_ultimate_div_mod(&a, &b);
	result[0] = a + 48;
	result[1] = b + 48;
	write(1, &result, 2);
}
