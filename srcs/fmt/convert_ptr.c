/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:36:36 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 18:52:01 by pguthaus         ###   ########.fr       */
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

static void					convert_ptr_negativ(t_state *state, t_fmt fmt, size_t len)
{
	size_t					minwidth;

	minwidth = MAX(len, fmt.minwidth);
	state->count += write_ptr(state->buff, fmt.value.u, (fmt.precised ? len - (PTR_LEN - 2) : 0), PTR_LEN - 2);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void					convert_ptr_zeropad(t_state *state, t_fmt fmt, size_t len)
{
	size_t					minwidth;

	minwidth = MAX(len, fmt.minwidth);
	state->count += write_ptr(state->buff, fmt.value.u, minwidth - len, (PTR_LEN - 2));
}

static void					convert_ptr_default(t_state *state, t_fmt fmt, size_t len)
{
	size_t					minwidth;

	minwidth = MAX(len, fmt.minwidth);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
	state->count += write_ptr(state->buff, fmt.value.u, (fmt.precised ? len - (PTR_LEN - 2) : 0), PTR_LEN - 2);
}

void						convert_ptr(t_state *state, t_fmt fmt)
{
	size_t					len;

	len = (fmt.precised ? fmt.precision : PTR_LEN);
	if (fmt.flags & FLAG_NEGATIV)
		convert_ptr_negativ(state, fmt, len);
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
		convert_ptr_zeropad(state, fmt, len);
	else
		convert_ptr_default(state, fmt, len);
}
