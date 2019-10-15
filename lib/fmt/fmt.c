/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:03 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 18:20:35 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

static t_fmt		get_initial_fmt()
{
	return ((t_fmt){ 0, 0, 0 });
}

static t_fmt		parse_flags(t_state *state, t_fmt fmt)
{
}

static t_fmt		parse_minwidth(t_state *state, t_fmt fmt)
{
}

static t_fmt		parse_precision(t_state *state, t_fmt fmt)
{
}

void				fmt(t_state *state)
{
	t_fmt			fmt;

	state->frmt++;
	fmt = get_initial_fmt();
	fmt = parse_flags(state, fmt);
	fmt = parse_minwidth(state, fmt);
	fmt = parse_precision(state, fmt);
	if (!(fmt.convert_func = g_conversions[(unsigned char)*state->frmt]))
		return ;
	state->frmt++;
}
