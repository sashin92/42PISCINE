/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:05:38 by sashin            #+#    #+#             */
/*   Updated: 2020/11/04 21:05:00 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_str_length(char *str)
{
	unsigned int		i;
	unsigned int		length;

	i = 0;
	while (str[i])
		++i;
	length = i;
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		d_length;
	unsigned int		s_length;
	unsigned int		i;

	d_length = ft_str_length(dest);
	s_length = ft_str_length(src);
	i = 0;
	while ((i + d_length + 1) < size && src[i])
	{
		dest[i + d_length] = src[i];
		++i;
	}
	dest[i + d_length] = 0;
	return (d_length >= size ? (s_length + size) : (s_length + d_length));
}
