/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:59:45 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/16 13:50:18 by pguthaus         ###   ########.fr       */
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
		buff_write_uchar(state->buff, value);
		buff_write_nchar(state->buff, min_width - len, ' ');
	}
	else if (fmt.flags & FLAG_ZEROPAD)
	{
		buff_write_nchar(state->buff, min_width - len, '0');
		buff_write_uchar(state->buff, value);
	}
	else
	{
		buff_write_nchar(state->buff, min_width - len, ' ');
		buff_write_uchar(state->buff, value);
	}
}
