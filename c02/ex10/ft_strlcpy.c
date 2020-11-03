/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 22:33:57 by sashin            #+#    #+#             */
/*   Updated: 2020/10/27 15:23:08 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (*(src + count))
		++count;
	if (size == 0)
		return (count);
	else if (size == 1)
	{
		*dest = 0;
		return (count);
	}
	else
		while (i < size - 1 && *(src + i) != 0)
		{
			*(dest + i) = *(src + i);
			++i;
		}
	if (i == size - 1 || *(src + i) == 0)
		*(dest + i) = 0;
	return (count);
}
