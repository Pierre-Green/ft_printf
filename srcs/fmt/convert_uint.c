/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:10:43 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 15:55:09 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

static size_t				write_uint(unsigned int value, t_buff *buff,
	size_t len)
{
	size_t					count;

	count = 0;
	if (len)
	{
		count += buff_write_nchar(buff, len - ft_count_digits(value), '0');
		count += buff_write_uint(buff, value);
	}
	return (count);
}

static void					convert_uint_negativ(t_state *state, t_fmt fmt, const unsigned int value, size_t len)
{
	size_t					minwidth;

	minwidth = MAX(len, fmt.min_width);
	state->count += write_uint(value, state->buff, len);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void					convert_uint_zeropad(t_state *state, t_fmt fmt, const unsigned int value, size_t len)
{
	size_t					minwidth;

	minwidth = MAX(len, fmt.min_width);
	state->count += write_uint(value, state->buff, minwidth);
}

static void					convert_uint_default(t_state *state, t_fmt fmt, const unsigned int value, size_t len)
{
	size_t					minwidth;

	minwidth = MAX(len, fmt.min_width);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
	state->count += write_uint(value, state->buff, len);
}

void						convert_uint(t_state *state, t_fmt fmt)
{
	const unsigned int		value = va_arg(state->args, int);
	size_t					len;

	len = MAX(ft_count_digits(value), fmt.precision);
	if (value == 0 && fmt.precised && !fmt.precision)
		len = 0;
	if (fmt.flags & FLAG_NEGATIV)
		convert_uint_negativ(state, fmt, value, len);
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
		convert_uint_zeropad(state, fmt, value, len);
	else
		convert_uint_default(state, fmt, value, len);
}
