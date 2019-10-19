/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:36:36 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/19 16:03:04 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

static size_t				write_ptr(t_buff *buff, unsigned long int val,
	size_t zero_len, char precprint)
{
	size_t					count;

	count = 0;
	count += buff_write_str(buff, "0x");
	count += buff_write_nchar(buff, zero_len, '0');
	if (precprint)
		count += buff_write_hex(buff, val, 0);
	return (count);
}

void						convert_ptr(t_state *state, t_fmt fmt)
{
	const unsigned long int	value = va_arg(state->args, long int);
	size_t					len;
	size_t					min_width;
	size_t					j;

	j = 12;
	len = 14;
	if (!value)
	{
		len = 3;
		j = (fmt.precised && fmt.precision == 0 ? 0 : 1);
	}
	len = (fmt.precised ? fmt.precision : len);
	min_width = MAX(len, fmt.min_width);
	if (fmt.flags & FLAG_NEGATIV)
	{
		state->count += write_ptr(state->buff, value,
			(fmt.precised ? len - j : 0), j);
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
	}
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
	{
		state->count += write_ptr(state->buff, value, min_width - len, j);
	}
	else
	{
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
		state->count += write_ptr(state->buff, value,
			(fmt.precised ? len - j : 0), j);
	}
}
