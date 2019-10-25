/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:11 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/25 16:58:26 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H
# include <stdint.h>
# include <stdlib.h>
# include "state.h"
# include "libft.h"
# define FLAG_ZEROPAD 0x0F000000
# define FLAG_NEGATIV 0x00F00000
# define OUT_NULL "(null)"
# define MAX(a, b) (a >= b ? a : b)
# define MIN(a, b) (a >= b ? b : a)
# define ABS(a) (a < 0 ? a * -1 : a)
# define PTR_LEN 14

typedef uint32_t			t_flag;

typedef struct				s_fmt
{
	t_flag					flags;
	size_t					minwidth;
	char					precised;
	ssize_t					precision;
}							t_fmt;
void						fmt(t_state *state);

static t_flag				g_flags[1 << 7] = {
	['0'] = FLAG_ZEROPAD,
	['-'] = FLAG_NEGATIV
};

typedef void				(*t_convert_func)(t_state *, t_fmt);
void						convert_char(t_state *state, t_fmt fmt);
void						convert_str(t_state *state, t_fmt fmt);
void						convert_ptr(t_state *state, t_fmt fmt);
void						convert_int(t_state *state, t_fmt fmt);
void						convert_uint(t_state *state, t_fmt fmt);
void						convert_hex(t_state *state, t_fmt fmt);
void						convert_hex_up(t_state *state, t_fmt fmt);
static t_convert_func		g_conversions[1 << 7] = {
	['c'] = convert_char,
	['s'] = convert_str,
	['p'] = convert_ptr,
	['d'] = convert_int,
	['i'] = convert_int,
	['u'] = convert_uint,
	['x'] = convert_hex,
	['X'] = convert_hex_up,
};

#endif
