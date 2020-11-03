/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 23:20:24 by sashin            #+#    #+#             */
/*   Updated: 2020/10/27 13:42:11 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int					i;
	unsigned char		hexc[2];
	unsigned char		cstr;

	i = 0;
	while (*(str + i))
	{
		cstr = *(str + i);
		if (cstr >= 32 && cstr <= 126)
			write(1, &cstr, 1);
		else
		{
			hexc[0] = cstr / 16 + 48;
			if (hexc[0] >= 58)
				hexc[0] = hexc[0] + 39;
			hexc[1] = cstr % 16 + 48;
			if (hexc[1] >= 58)
				hexc[1] = hexc[1] + 39;
			write(1, "\\", 1);
			write(1, hexc, 2);
		}
		++i;
	}
}
