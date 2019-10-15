/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:06:38 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 20:07:31 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "buff.h"

void						convert_str(t_state *state, t_fmt fmt)
{
	buff_write_str(state->buff, va_arg(state->args, char *));
}
