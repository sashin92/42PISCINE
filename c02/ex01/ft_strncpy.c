/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:48:59 by sashin            #+#    #+#             */
/*   Updated: 2020/10/27 19:35:13 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (i < n && (*(src + i) != 0))
	{
		*(dest + i) = *(src + i);
		++i;
	}
	while (i < n)
	{
		*(dest + i) = 0;
		++i;
	}
	return (dest);
}
