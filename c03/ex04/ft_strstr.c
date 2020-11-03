/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:24:47 by sashin            #+#    #+#             */
/*   Updated: 2020/10/26 21:02:08 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			check(char *str, char *to_find, int i)
{
	int j;

	j = 0;
	while (*(to_find + j))
	{
		if (*(str + i) == *(to_find + j))
		{
			++i;
			++j;
		}
		else
			break ;
	}
	if (*(to_find + j) == 0)
		return (1);
	return (0);
}

char		*ft_strstr(char *str, char *to_find)
{
	int		pt;
	int		i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == *to_find)
		{
			pt = i;
			if (check(str, to_find, i) == 1)
				return (str + pt);
		}
		++i;
	}
	if (*to_find == 0)
		return (str);
	else
		return (0);
}
