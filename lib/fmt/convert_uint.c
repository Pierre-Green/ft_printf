/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:10:43 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 15:21:30 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

static size_t					write_uint(unsigned int value, t_buff *buff,
	size_t len)
{
	size_t					count;

	count = 0;
	count += buff_write_nchar(buff, len - ft_count_digits(value), '0');
	count += buff_write_uint(buff, value);
	return (count);
}

void						convert_uint(t_state *state, t_fmt fmt)
{
	const unsigned int		value = va_arg(state->args, int);
	size_t					len;
	size_t					min_width;

	len = MAX(ft_count_digits(value), fmt.precision);
	min_width = MAX(len, fmt.min_width);
	if (fmt.flags & FLAG_NEGATIV)
	{
		state->count += write_uint(value, state->buff, len);
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
	}
	else if (fmt.flags & FLAG_ZEROPAD && !fmt.precised)
	{
		state->count += write_uint(value, state->buff, min_width);
	}
	else
	{
		state->count += buff_write_nchar(state->buff, min_width - len, ' ');
		state->count += write_uint(value, state->buff, len);
	}
}
