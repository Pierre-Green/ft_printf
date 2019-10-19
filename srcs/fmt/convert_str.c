/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:06:38 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/19 15:38:24 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

static size_t				fmt_strlen(char *str, t_fmt fmt)
{
	size_t					i;

	i = 0;
	if (!str)
		i = 6;
	else
		while (*(str + i))
			i++;
	return ((fmt.precised ? MIN(i, fmt.precision) : i));
}

void						convert_str(t_state *state, t_fmt fmt)
{
	const char				*value = va_arg(state->args, char *);
	const size_t			len = fmt_strlen((char *)value, fmt);
	const size_t			min_width = MAX(len, fmt.min_width);

	if (!value)
		value = "(null)";
	if (fmt.flags & FLAG_NEGATIV)
	{
		state->count += buff_write_strl(state->buff, (char *)value, len);
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
	}
	else if (fmt.flags & FLAG_ZEROPAD)
	{
		state->count += buff_write_nchar(state->buff, min_width - len, '0');
		state->count += buff_write_strl(state->buff, (char *)value, len);
	}
	else
	{
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
		state->count += buff_write_strl(state->buff, (char *)value, len);
	}
}
