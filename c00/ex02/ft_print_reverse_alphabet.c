/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <aopaoi0987@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:28:53 by sashin            #+#    #+#             */
/*   Updated: 2020/10/20 10:59:03 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	rev_alphabet;

	rev_alphabet = 'z';
	while (rev_alphabet >= 'a')
	{
		write(1, &rev_alphabet, 1);
		--rev_alphabet;
	}
}
