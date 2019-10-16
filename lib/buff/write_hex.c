/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:30:38 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/16 15:44:20 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buff.h"

size_t				buff_write_hex(t_buff *buff, unsigned int n, char uppercase)
{
	char			t_buff[8];
	size_t			i;
	unsigned int	tmp;

	i = 0;
	(void)uppercase;
	while (n)
	{
		tmp = n % 16;
		if (tmp < 10)
			t_buff[i] = tmp + 48;
		else
			t_buff[i] = (uppercase ? tmp + 55 : tmp + 87);
		i++;
		n /= 16;
	}
	tmp = i;
	while (tmp > 0)
	{
		buff_write_uchar(buff, t_buff[tmp - 1]);
		tmp--;
	}
	return (i);
}
