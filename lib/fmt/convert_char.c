/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:59:45 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 15:12:55 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

void						convert_char(t_state *state, t_fmt fmt)
{
	const size_t			min_width = MAX(fmt.min_width, 1);
	const size_t			len = 1;
	unsigned char			value;

	value = va_arg(state->args, int);
	if (fmt.flags & FLAG_NEGATIV)
	{
		state->count += buff_write_uchar(state->buff, value);
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
	}
	else if (fmt.flags & FLAG_ZEROPAD)
	{
		state->count += buff_write_nchar(state->buff, min_width - len, '0');
		state->count += buff_write_uchar(state->buff, value);
	}
	else
	{
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
		state->count += buff_write_uchar(state->buff, value);
	}
}
