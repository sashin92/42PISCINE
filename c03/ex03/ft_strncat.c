/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:39:57 by sashin            #+#    #+#             */
/*   Updated: 2020/10/27 20:00:18 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	while (*(dest + i))
		++i;
	while (j < nb && *(src + j) != 0)
	{
		*(dest + i) = *(src + j);
		++j;
		++i;
	}
	*(dest + i) = 0;
	return (dest);
}
