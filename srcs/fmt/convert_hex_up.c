/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:20:47 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 18:48:54 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

static size_t				write_hex(t_buff *buff, unsigned int value, size_t zero_len)
{
	size_t					count;

	count = 0;
	count += buff_write_nchar(buff, zero_len, '0');
	count += buff_write_hex(buff, value, 42);
	return (count);
}

static void					convert_hex_negativ(t_state *state, t_fmt fmt, size_t len)
{
	const size_t			minwidth = MAX(len, fmt.minwidth);
	const unsigned int		value = fmt.value.u;

	state->count += write_hex(state->buff, value, len - ft_count_uint_base(value, 16));
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void					convert_hex_zeropad(t_state *state, t_fmt fmt, size_t len)
{
	const size_t			minwidth = MAX(len, fmt.minwidth);
	const unsigned int		value = fmt.value.u;

	state->count += write_hex(state->buff, value, minwidth - len);
}

static void					convert_hex_default(t_state *state, t_fmt fmt, size_t len)
{
	const size_t			minwidth = MAX(len, fmt.minwidth);
	const unsigned int		value = fmt.value.u;

	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
	state->count += write_hex(state->buff, value, len - ft_count_uint_base(value, 16));
}

void						convert_hex_up(t_state *state, t_fmt fmt)
{
	const size_t			len = MAX(ft_count_uint_base(fmt.value.u, 16), fmt.precision);

	if (fmt.flags & FLAG_NEGATIV)
		convert_hex_negativ(state, fmt, len);
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
		convert_hex_zeropad(state, fmt, len);
	else
		convert_hex_default(state, fmt, len);
}
