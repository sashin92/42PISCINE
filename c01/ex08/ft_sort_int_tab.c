/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:48:46 by sashin            #+#    #+#             */
/*   Updated: 2020/10/21 18:27:34 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int temp;
	int i;
	int j;

	j = 0;
	while (!(j == (size - 1)))
	{
		i = j + 1;
		while (!(i == size))
		{
			if (*(tab + j) > *(tab + i))
			{
				temp = *(tab + j);
				*(tab + j) = *(tab + i);
				*(tab + i) = temp;
			}
			++i;
		}
		++j;
	}
}
