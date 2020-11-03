/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:35:55 by sashin            #+#    #+#             */
/*   Updated: 2020/10/22 01:53:36 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_div_mod(int a, int b, int *div, int *mod);

int			main(void)
{
	int		a;
	int		b;
	int		divi;
	int		modi;
	char	result[2];

	a = 5;
	b = 3;
	ft_div_mod(a, b, &divi, &modi);
	result[0] = divi + 48;
	result[1] = modi + 48;
	write(1, &result, 2);
}
