/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:54:11 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 19:05:06 by pguthaus         ###   ########.fr       */
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

typedef void				(*t_convert_func)();

typedef uint32_t			t_flag;

void						convert_char();

static t_flag				g_flags[1 << 7] = {
	['#'] = FLAG_ALTERNA,
	['0'] = FLAG_ZEROPAD,
	['-'] = FLAG_NEGATIV,
	[' '] = FLAG_SPACEAL,
	['+'] = FLAG_SIGNMUS,
	['\''] = FLAG_APOSTRO
};

static t_convert_func		g_conversions[1 << 7] = {
	['c'] = convert_char
};

typedef struct				s_fmt
{
	t_flag					flags;
	size_t					min_width;
	char					precised;
	size_t					precision;
	t_convert_func			convert_func;
}							t_fmt;

void						fmt(t_state *state);

#endif
