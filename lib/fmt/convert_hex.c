/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:13:41 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 16:25:43 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

static size_t				fmt_hexlen(unsigned int value)
{
	size_t					i;

	i = 0;
	while (value)
	{
		i++;
		value /= 16;
	}
	return (i);
}

static size_t				write_hex(t_buff *buff, unsigned int value,
	char uppercase, size_t zero_len)
{
	size_t					count;

	count = 0;
	count += buff_write_nchar(buff, zero_len, '0');
	count += buff_write_hex(buff, value, uppercase);
	return (count);
}

static void					convert_hex_internal(t_state *state, t_fmt fmt,
	char uppercase)
{
	const unsigned int		value = va_arg(state->args, int);
	const size_t			len = MAX(fmt_hexlen(value), fmt.precision);
	const size_t			min_width = MAX(len, fmt.min_width);

	if (fmt.flags & FLAG_NEGATIV)
	{
		state->count += write_hex(state->buff, value, uppercase,
			len - fmt_hexlen(value));
		state->count += buff_write_nchar(state->buff,
			min_width - len, ' ');
	}
	else if (fmt.flags & FLAG_ZEROPAD)
	{
		state->count += write_hex(state->buff, value, uppercase,
			min_width - len);
	}
	else
	{
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
		state->count += write_hex(state->buff, value, uppercase,
			len - fmt_hexlen(value));
	}
}

void						convert_hex(t_state *state, t_fmt fmt)
{
	convert_hex_internal(state, fmt, 0);
}

void						convert_hex_up(t_state *state, t_fmt fmt)
{
	convert_hex_internal(state, fmt, 42);
}
