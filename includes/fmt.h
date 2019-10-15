/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:11 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 18:04:45 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H
# include <stdint.h>
# include <stdlib.h>
# include "state.h"
# define FLAG_NEG 0xF000
# define FLAG_ZER 0x0F00
# define FLAG_PRE 0x00F0

typedef void				(*t_convert_func)();

typedef uint16_t			t_flag;

void						convert_char();

static t_flag				g_flags[1 << 7] = {
	['-'] = FLAG_NEG,
	['0'] = FLAG_ZER,
	['.'] = FLAG_PRE
};

void						convert_char();

static t_convert_func		g_conversions[1 << 7] = {
	['c'] = convert_char
};

typedef struct				s_fmt
{
	t_convert_func			convert_func;
	t_flag					flags;
	size_t					precision;
}							t_fmt;

void						fmt(t_state *state);

#endif
