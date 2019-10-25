/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:03 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 14:28:30 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

static t_fmt		get_initial_fmt(void)
{
	return ((t_fmt){ 0, 0, 0, 0 });
}

static t_fmt		parse_flags(t_state *state, t_fmt fmt)
{
	t_flag			flag;

	while ((flag = g_flags[(unsigned char)*state->frmt]))
	{
		fmt.flags |= flag;
		state->frmt++;
	}
	return (fmt);
}

static t_fmt		parse_minwidth(t_state *state, t_fmt fmt)
{
	while (*state->frmt >= '0' && *state->frmt <= '9')
	{
		fmt.min_width *= 10;
		fmt.min_width += (*state->frmt) - '0';
		state->frmt++;
	}
	return (fmt);
}

static t_fmt		parse_precision(t_state *state, t_fmt fmt)
{
	int				fac;

	fac = 1;
	if (*state->frmt && *state->frmt == '.')
	{
		state->frmt++;
		fmt.precised = 42;
		if (*state->frmt == '-')
		{
			fac = -1;
			state->frmt++;
		}
		while (*state->frmt >= '0' && *state->frmt <= '9')
		{
			fmt.precision *= 10;
			fmt.precision += (*state->frmt) - '0';
			state->frmt++;
		}
		fmt.precision *= fac;
	}
	return (fmt);
}

void				fmt(t_state *state)
{
	t_fmt			fmt;
	t_convert_func	f_convert;

	state->frmt++;
	fmt = get_initial_fmt();
	fmt = parse_flags(state, fmt);
	fmt = parse_minwidth(state, fmt);
	fmt = parse_precision(state, fmt);
	f_convert = 0;
	if (*state->frmt == '%')
		state->count += buff_write_uchar(state->buff, '%');
	else if (!(f_convert = g_conversions[(unsigned char)*state->frmt]))
		return ;
	state->frmt++;
	if (f_convert)
		f_convert(state, fmt);
}
