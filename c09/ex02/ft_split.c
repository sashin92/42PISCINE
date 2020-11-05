/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:17:13 by sashin            #+#    #+#             */
/*   Updated: 2020/11/05 17:45:57 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int						ft_is_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}

int						ft_str_count(char *str, char *charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_is_charset(str[i], charset))
		{
			++count;
			while (!ft_is_charset(str[i], charset) && str[i])
				++i;
		}
		else
			++i;
	}
	return (count);
}

int						ft_str_length(char *str, char *charset)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (!ft_is_charset(str[i], charset) && str[i])
	{
		++length;
		++i;
	}
	return (length);
}

char					*ft_strdup(char *src, int length)
{
	int		i;
	char	*str;

	str = (char*)malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i < length)
	{
		str[i] = src[i];
		++i;
	}
	str[i] = 0;
	return (str);
}

char					**ft_split(char *str, char *charset)
{
	char	**str_arr;
	int		count;
	int		i;
	int		arr_i;
	int		length;

	count = ft_str_count(str, charset);
	str_arr = (char **)malloc(sizeof(char *) * (count + 1));
	i = 0;
	arr_i = 0;
	while (str[i])
	{
		if (!ft_is_charset(str[i], charset))
		{
			length = ft_str_length(&str[i], charset);
			str_arr[arr_i] = ft_strdup(&str[i], length);
			++arr_i;
			while (!ft_is_charset(str[i], charset) && str[i])
				++i;
		}
		else
			++i;
	}
	str_arr[arr_i] = 0;
	return (str_arr);
}
