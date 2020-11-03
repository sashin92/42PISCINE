/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:07:32 by sashin            #+#    #+#             */
/*   Updated: 2020/11/02 14:29:42 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
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
