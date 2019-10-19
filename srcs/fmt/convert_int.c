/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:10:43 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/19 18:57:58 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

static size_t				write_int(int value, t_buff *buff, size_t len)
{
	unsigned int			u_value;
	size_t					count;

	count = 0;
	if (value < 0)
	{
		len--;
		count += buff_write_uchar(buff, '-');
		u_value = (unsigned int)(value) * -1;
	}
	else
	{
		u_value = (unsigned int)value;
	}
	if (len)
	{
		count += buff_write_nchar(buff, len - ft_count_digits(value), '0');
		count += buff_write_uint(buff, u_value);
	}
	return (count);
}

void						convert_int(t_state *state, t_fmt fmt)
{
	const int				value = va_arg(state->args, int);
	size_t					len;
	size_t					min_width;

	len = MAX(ft_count_digits(value), fmt.precision);
	if (value < 0)
		len++;
	if (value == 0 && fmt.precised && !fmt.precision)
		len = 0;
	min_width = MAX(len, fmt.min_width);
	if (fmt.flags & FLAG_NEGATIV)
	{
		state->count += write_int(value, state->buff, len);
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
	}
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
	{
		state->count += write_int(value, state->buff, min_width);
	}
	else
	{
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
		state->count += write_int(value, state->buff, len);
	}
}
