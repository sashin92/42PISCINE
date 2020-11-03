/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 21:17:16 by sashin            #+#    #+#             */
/*   Updated: 2020/10/25 18:40:55 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) = *(str + i) + 32;
		++i;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int upper;

	ft_strlowcase(str);
	i = 0;
	upper = 1;
	while (*(str + i))
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
			upper = 0;
		else if (*(str + i) >= 'a' && *(str + i) <= 'z')
		{
			if (upper == 1)
			{
				*(str + i) = *(str + i) - 32;
				upper = 0;
			}
		}
		else
			upper = 1;
		++i;
	}
	return (str);
}
