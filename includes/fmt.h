/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:11 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 20:16:23 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H
# include <stdint.h>
# include <stdlib.h>
# include "state.h"
# define FLAG_ALTERNA 0xF0000000
# define FLAG_ZEROPAD 0x0F000000
# define FLAG_NEGATIV 0x00F00000
# define FLAG_SPACEAL 0x000F0000
# define FLAG_SIGNMUS 0x0000F000
# define FLAG_APOSTRO 0x00000F00

typedef uint32_t			t_flag;

typedef struct				s_fmt
{
	t_flag					flags;
	size_t					min_width;
	char					precised;
	size_t					precision;
}							t_fmt;
void						fmt(t_state *state);

static t_flag				g_flags[1 << 7] = {
	['#'] = FLAG_ALTERNA,
	['0'] = FLAG_ZEROPAD,
	['-'] = FLAG_NEGATIV,
	[' '] = FLAG_SPACEAL,
	['+'] = FLAG_SIGNMUS,
	['\''] = FLAG_APOSTRO
};

typedef void				(*t_convert_func)(t_state *, t_fmt);
void						convert_char(t_state *state, t_fmt fmt);
void						convert_str(t_state *state, t_fmt fmt);
void						convert_int(t_state *state, t_fmt fmt);
void						convert_uint(t_state *state, t_fmt fmt);
void						convert_hex(t_state *state, t_fmt fmt);
void						convert_hex_up(t_state *state, t_fmt fmt);
static t_convert_func		g_conversions[1 << 7] = {
	['c'] = convert_char,
	['s'] = convert_str,
	['d'] = convert_int,
	['i'] = convert_int,
	['u'] = convert_uint,
	['x'] = convert_hex,
	['X'] = convert_hex_up
};

#endif
