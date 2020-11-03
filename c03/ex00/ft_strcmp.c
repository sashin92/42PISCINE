/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:27:14 by sashin            #+#    #+#             */
/*   Updated: 2020/10/27 10:58:05 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (*(s1 + i) != 0 || *(s2 + i) != 0)
	{
		if (*(s1 + i) != *(s2 + i))
			break ;
		++i;
	}
	return (*(s1 + i) - *(s2 + i));
}
