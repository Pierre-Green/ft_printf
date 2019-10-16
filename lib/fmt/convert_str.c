/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:06:38 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/16 13:04:00 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

static size_t				fmt_strlen(char *str, t_fmt fmt)
{
	size_t					i;

	i = 0;
	while (*(str + i))
		i++;
	return ((fmt.precised ? MIN(i, fmt.precision) : i));
}

void						convert_str(t_state *state, t_fmt fmt)
{
	const char				*value = va_arg(state->args, char *);
	const size_t			len = fmt_strlen((char *)value, fmt);
	const size_t			min_width = MAX(len, fmt.min_width);

	if (fmt.flags & FLAG_NEGATIV)
	{
		buff_write_strl(state->buff, (char *)value, len);
		buff_write_nchar(state->buff, min_width - len, ' ');
	}
	else if (fmt.flags & FLAG_ZEROPAD)
	{
		buff_write_nchar(state->buff, min_width - len, '0');
		buff_write_strl(state->buff, (char *)value, len);
	}
	else
	{
		buff_write_nchar(state->buff, min_width - len, ' ');
		buff_write_strl(state->buff, (char *)value, len);
	}
}
