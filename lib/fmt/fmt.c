/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:03 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 17:59:08 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

void				fmt(t_state *state)
{
	t_fmt			fmt;

	state->frmt++;
	fmt.flags = 0;
	fmt.precision = 0;
	fmt.convert_func = 0;
	while (*state->frmt && g_flags[(unsigned char)*state->frmt])
	{
		fmt.flags |= g_flags[(unsigned char)*state->frmt];
		state->frmt++;
	}
	if (*state->frmt && !g_conversions[(unsigned char)*state->frmt])
		fmt.convert_func = g_conversions[(unsigned char)*state->frmt];
	state->frmt++;
}
