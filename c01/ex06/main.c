/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:29:08 by sashin            #+#    #+#             */
/*   Updated: 2020/10/22 02:03:08 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_strlen(char	*str);

int			main(void)
{
	char	str[6];
	int		count;
	char	display_count;

	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';
	count = ft_strlen(str);
	display_count = count + 48;
	write(1, &display_count, 1);
}
