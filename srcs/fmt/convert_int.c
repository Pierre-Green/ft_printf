/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:10:43 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 17:11:59 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

static size_t				write_int(int value, t_buff *buff, size_t len, size_t minwidth)
{
	unsigned int			u_value;
	size_t					count;

	count = 0;
	u_value = (unsigned int)value;
	if (value < 0)
	{
		len++;
		count += buff_write_uchar(buff, '-');
		u_value = (unsigned int)(value) * -1;
	}
	if (len)
	{
		count += buff_write_nchar(buff, minwidth - len, '0');
		count += buff_write_uint(buff, u_value);
	}
	return (count);
}

static void				convert_int_negativ(t_state *state, t_fmt fmt, const int value, size_t len)
{
	size_t				minwidth;
	size_t				count;

	count = ft_count_uint_base(ABS(value), 10);
	minwidth = MAX(len, fmt.minwidth);
	if (fmt.precision < 0)
		minwidth = MAX(minwidth, fmt.precision * -1);
	state->count += write_int(value, state->buff, count, len);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void				convert_int_zeropad(t_state *state, t_fmt fmt, const int value)
{
	size_t				len;
	size_t				minwidth;

	len = ft_count_uint_base(value, 10);
	minwidth = MAX(len, fmt.minwidth);
	state->count += write_int(value, state->buff, len, minwidth);
}

static void				convert_int_default(t_state *state, t_fmt fmt, const int value, size_t len)
{
	size_t				minwidth;
	size_t				count;

	count = ft_count_uint_base(ABS(value), 10);
	if (fmt.precision < 0)
		convert_int_negativ(state, fmt, value, len);
	else
	{
		minwidth = MAX(len, fmt.minwidth);
		state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
		state->count += write_int(value, state->buff, count, len);
	}
}

void						convert_int(t_state *state, t_fmt fmt)
{
	const int				value = va_arg(state->args, int);
	size_t					len;

	len = ft_count_uint_base(ABS(value), 10);
	if (value < 0)
		len++;
	if (fmt.precision >= 0)
		len = MAX(len, fmt.precision);
	if (fmt.flags & FLAG_NEGATIV)
		convert_int_negativ(state, fmt, value, len);
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
		convert_int_zeropad(state, fmt, value);
	else
		convert_int_default(state, fmt, value, len);
}
