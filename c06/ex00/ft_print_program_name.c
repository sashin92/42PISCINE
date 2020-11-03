/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:54:07 by sashin            #+#    #+#             */
/*   Updated: 2020/10/29 22:17:07 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	(void)argc;
	while (argv[0][i])
	{
		write(1, &argv[0][i], sizeof(char));
		++i;
	}
	return (0);
}
