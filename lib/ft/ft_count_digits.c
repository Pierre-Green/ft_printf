/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:33:55 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/16 16:37:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t				ft_count_digits(unsigned int n)
{
	size_t			pow;

	pow = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		pow++;
		n /= 10;
	}
	return (pow);
}
