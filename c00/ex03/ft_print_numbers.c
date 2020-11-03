/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:38:15 by sashin            #+#    #+#             */
/*   Updated: 2020/10/20 11:02:19 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	print_numbers;

	print_numbers = '0';
	while (print_numbers <= '9')
	{
		write(1, &print_numbers, 1);
		++print_numbers;
	}
}
