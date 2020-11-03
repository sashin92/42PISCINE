/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghkim <sanghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:35:36 by sanghkim          #+#    #+#             */
/*   Updated: 2020/11/01 20:27:14 by sanghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_print_error(char *str)
{
	ft_putstr(str);
}

int		ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ');
}

int		ft_is_valid_param(void)
{
	int		idx;

	if (!g_number || !g_number[0] ||
			(ft_strlen(g_number) > 1 && g_number[0] == '0'))
		return (0);
	idx = 0;
	while (g_number[idx])
	{
		if (g_number[idx] >= '0' && g_number[idx] <= '9')
			idx++;
		else
			return (0);
	}
	return (1);
}

int		ft_is_valid_buffer(void)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (g_buffer[i])
	{
		if (g_buffer[i] >= '0' && g_buffer[i] <= '9')
			check = 1;
		else if (ft_is_space(g_buffer[i])
				&& (check == 1 || check == 2))
			;
		else if (g_buffer[i] == ':' && check == 1)
			check = 2;
		else if (g_buffer[i] >= 32 && g_buffer[i] <= 126
				&& (check == 2 || check == 3))
			check = 3;
		else if (g_buffer[i] == '\n' && (check == 3 || check == 0))
			check = 0;
		else
			return (0);
		++i;
	}
	return (1);
}
