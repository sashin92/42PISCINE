/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:05:38 by sashin            #+#    #+#             */
/*   Updated: 2020/11/02 21:29:44 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	count_dest(char *dest, unsigned int size, unsigned int i)
{
	while (*(dest + i))
	{
		if (i < size)
			++i;
		else
			break ;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		val;

	i = 0;
	j = 0;
	while (*(src + j))
		++j;
	i = count_dest(dest, size, i);
	val = i + j;
	j = 0;
	while (i < size && *(src + j) != 0)
	{
		*(dest + i) = *(src + j);
		++i;
		++j;
		if (i == size)
			dest[i - 1] = 0;
	}
	while (i < size)
	{
		dest[i] = 0;
		++i;
	}
	return (val);
}
