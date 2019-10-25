/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:06:38 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 15:45:38 by pguthaus         ###   ########.fr       */
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

static void					convert_str_negativ(t_state *state, t_fmt fmt, const char *value, size_t len)
{
	size_t					minwidth;

	minwidth = MAX(len, fmt.min_width);
	state->count += buff_write_strl(state->buff, (char *)value, len);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
}

static void					convert_str_zeropad(t_state *state, t_fmt fmt, const char *value, size_t len)
{
	size_t					minwidth;

	minwidth = MAX(len, fmt.min_width);
	state->count += buff_write_nchar(state->buff, minwidth - len, '0');
	state->count += buff_write_strl(state->buff, (char *)value, len);
}

static void					convert_str_default(t_state *state, t_fmt fmt, const char *value, size_t len)
{
	size_t					minwidth;

	minwidth = MAX(len, fmt.min_width);
	state->count += buff_write_nchar(state->buff, minwidth - len, ' ');
	state->count += buff_write_strl(state->buff, (char *)value, len);
}

void						convert_str(t_state *state, t_fmt fmt)
{
	const char				*value = va_arg(state->args, char *);
	const size_t			len = fmt_strlen((char *)value, fmt);

	if (!value)
		value = "(null)";
	if (fmt.flags & FLAG_NEGATIV)
		convert_str_negativ(state, fmt, value, len);
	else if (fmt.flags & FLAG_ZEROPAD)
		convert_str_zeropad(state, fmt, value, len);
	else
		convert_str_default(state, fmt, value, len);
}
