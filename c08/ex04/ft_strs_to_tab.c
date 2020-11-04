/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:32:12 by sashin            #+#    #+#             */
/*   Updated: 2020/11/05 00:27:43 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char					*ft_strdup(char *src)
{
	int		i;
	int		src_length;
	char	*str;

	i = 0;
	while (src[i])
		++i;
	src_length = i;
	str = (char*)malloc(sizeof(char) * (src_length + 1));
	i = 0;
	while (i < src_length)
	{
		str[i] = src[i];
		++i;
	}
	str[i] = 0;
	return (str);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*grup;

	grup = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		grup[i].str = av[i];
		grup[i].size = ft_strlen(av[i]);
		grup[i].copy = ft_strdup(av[i]);
		++i;
	}
	grup[i].str = 0;
	grup[i].size = 0;
	grup[i].copy = 0;
	return (grup);
}
