/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:19:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 16:31:20 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_state	*get_initial_state(const char *format, va_list args)
{
	t_state		*state;

	if (!(state = (t_state *)malloc(sizeof(t_state))))
		return (NULL);
	state->count = 0;
	state->frmt = (char *)format;
	if (!(state->buff = (t_buff *)malloc(sizeof(t_buff))))
	{
		state->buff->len = 64;
		clear_state(state);
		return (NULL);
	}
	return (state);
}

int				ft_printf_va(const char *format, va_list args)
{
	t_state		*state;

	if (!(state = get_initial_state(format, args)))
		return (-42);
	while (*state->frmt)
	{
		if (*state->frmt == '%')
			fmt(state);
		else
		{
			while (*state->frmt && *state->frmt != '%')
			{
				state->count += buff_write_char(state->buff, *state->frmt);
				state->frmt++;
			}
			continue ;
		}
		state->frmt++;
	}
	buff_flush(state->buff);
	clear_state(state);
	return (state->count);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	int			result;

	va_start(args, format);
	result = ft_printf_va(format, args);
	va_end(args);
	return (result);
}
