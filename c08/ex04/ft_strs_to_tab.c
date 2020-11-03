/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:32:12 by sashin            #+#    #+#             */
/*   Updated: 2020/11/03 20:14:50 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

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
	int				j;
	char			*string;
	t_stock_str		*grup;

	grup = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		j = 0;
		grup[i].size = 0;
		while (av[i][j])
		{
			string[j] = av[i][j];
			++(grup[i].size);
			++j;
		}
		string[j] = 0;
		grup[i].str = string;

		++i;
	}
}


int		main(argc, argv)