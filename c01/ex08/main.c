/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:28:24 by sashin            #+#    #+#             */
/*   Updated: 2020/10/22 13:18:13 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size);

int		main(void)
{
	int		size;
	int		tab[size];
	char	num[size];

	size = 5;
	tab[0] = 4;
	tab[1] = 1;
	tab[2] = 5;
	tab[3] = 3;
	tab[4] = 2;
	ft_sort_int_tab(tab, size);
	num[0] = tab[0] + 48;
	num[1] = tab[1] + 48;
	num[2] = tab[2] + 48;
	num[3] = tab[3] + 48;
	num[4] = tab[4] + 48;
	write(1, num, 5);
}
