/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:59:45 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 16:39:43 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

static void					convert_char_negativ(t_state *state, t_fmt fmt, const char value, size_t minwidth)
{
	state->count += buff_write_uchar(state->buff, value);
	state->count += buff_write_nchar(state->buff, minwidth - 1, ' ');
}

static void					convert_char_zeropad(t_state *state, t_fmt fmt, const char value, size_t minwidth)
{
	state->count += buff_write_nchar(state->buff, minwidth - 1, '0');
	state->count += buff_write_uchar(state->buff, value);
}

static void					convert_char_default(t_state *state, t_fmt fmt, const char value, size_t minwidth)
{
	state->count += buff_write_nchar(state->buff, minwidth - 1, ' ');
	state->count += buff_write_uchar(state->buff, value);
}

void						convert_char(t_state *state, t_fmt fmt)
{
	const size_t			minwidth = MAX(fmt.min_width, 1);
	const unsigned char		value = va_arg(state->args, int);

	if (fmt.flags & FLAG_NEGATIV)
		convert_char_negativ(state, fmt, value, minwidth);
	else if (fmt.flags & FLAG_ZEROPAD)
		convert_char_zeropad(state, fmt, value, minwidth);
	else
		convert_char_default(state, fmt, value, minwidth);
}
