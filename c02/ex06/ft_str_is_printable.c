/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:19:32 by sashin            #+#    #+#             */
/*   Updated: 2020/10/22 18:24:13 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 32 && *(str + i) <= 126)
			++i;
		else
			return (0);
	}
	return (1);
}
