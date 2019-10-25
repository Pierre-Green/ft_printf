/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:13:41 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 17:28:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

static size_t				write_hex(t_buff *buff, unsigned int value, size_t zero_len)
{
	size_t					count;

	count = 0;
	count += buff_write_nchar(buff, zero_len, '0');
	count += buff_write_hex(buff, value, 0);
	return (count);
}

static void					convert_hex_negativ(t_state *state, t_fmt fmt, const unsigned int value, size_t len)
{
	const size_t			minwidth = MAX(len, fmt.minwidth);

	state->count += write_hex(state->buff, value, len - ft_count_uint_base(value, 16));
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void					convert_hex_zeropad(t_state *state, t_fmt fmt, const unsigned int value, size_t len)
{
	const size_t			minwidth = MAX(len, fmt.minwidth);

	state->count += write_hex(state->buff, value, minwidth - len);
}

static void					convert_hex_default(t_state *state, t_fmt fmt, const unsigned int value, size_t len)
{
	const size_t			minwidth = MAX(len, fmt.minwidth);

	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
	state->count += write_hex(state->buff, value, len - ft_count_uint_base(value, 16));
}

void						convert_hex(t_state *state, t_fmt fmt)
{
	const unsigned int		value = va_arg(state->args, int);
	const size_t			len = MAX(ft_count_uint_base(value, 16), fmt.precision);

	if (fmt.flags & FLAG_NEGATIV)
		convert_hex_negativ(state, fmt, value, len);
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
		convert_hex_zeropad(state, fmt, value, len);
	else
		convert_hex_default(state, fmt, value, len);
}
