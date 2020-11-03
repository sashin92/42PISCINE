/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghkim <sanghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:19:44 by sanghkim          #+#    #+#             */
/*   Updated: 2020/11/01 15:17:41 by sanghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0' &&
					!(str[i + j + 1] >= '0' && str[i + j + 1] <= '9'))
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strndup(char *str, int n)
{
	char			*result;
	int				idx;

	if (!(result = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	idx = 0;
	while (idx < n)
	{
		result[idx] = str[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
