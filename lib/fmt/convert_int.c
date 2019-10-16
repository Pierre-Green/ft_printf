/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:10:43 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/16 15:11:51 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

static void					write_int(int value, t_buff *buff, size_t len)
{
	unsigned int			u_value;

	if (value < 0)
	{
		len--;
		buff_write_uchar(buff, '-');
		u_value = (unsigned int)(value) * -1;
	}
	else
	{
		u_value = (unsigned int)value;
	}
	buff_write_nchar(buff, len - ft_count_digits(value), '0');
	buff_write_uint(buff, u_value);
}

void						convert_int(t_state *state, t_fmt fmt)
{
	const int				value = va_arg(state->args, int);
	size_t					len;
	size_t					min_width;

	len = MAX(ft_count_digits(value), fmt.precision);
	if (value < 0)
		len++;
	min_width = MAX(len, fmt.min_width);
	if (fmt.flags & FLAG_NEGATIV)
	{
		write_int(value, state->buff, len);
		buff_write_nchar(state->buff, min_width - len, ' ');
	}
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
	{
		write_int(value, state->buff, min_width);
	}
	else
	{
		buff_write_nchar(state->buff, min_width - len, ' ');
		write_int(value, state->buff, len);
	}
}
