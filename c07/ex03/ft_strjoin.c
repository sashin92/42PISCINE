/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:39:49 by sashin            #+#    #+#             */
/*   Updated: 2020/11/02 20:45:48 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_length_all(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		sep_length;
	int		str_length;
	int		total_length;

	if (size <= 0)
		return (0);
	sep_length = 0;
	str_length = 0;
	while (sep[sep_length])
		++sep_length;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			++str_length;
			++j;
		}
		++i;
	}
	total_length = str_length + sep_length * (size - 1);
	return (total_length);
}

char		*ft_strcat(char *dest, char *src)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (dest[length])
		++length;
	while (src[i])
	{
		dest[length + i] = src[i];
		++i;
	}
	dest[length + i] = 0;
	return (dest);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*attach_str;
	int		length;

	if (size < 0)
		return (0);
	length = ft_length_all(size, strs, sep);
	attach_str = (char *)malloc(sizeof(char) * (length + 1));
	if (size == 0)
		return (attach_str);
	attach_str[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(attach_str, strs[i]);
		if (i < size - 1)
			ft_strcat(attach_str, sep);
		++i;
	}
	return (attach_str);
}
