/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:58:21 by sashin            #+#    #+#             */
/*   Updated: 2020/10/22 02:05:56 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size);

int		main(void)
{
	int		tab[3];
	int		size;
	char	num[3];

	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	size = 3;
	ft_rev_int_tab(tab, size);
	num[0] = tab[0] + 48;
	num[1] = tab[1] + 48;
	num[2] = tab[2] + 48;
	write(1, num, 3);
	return (0);
}
