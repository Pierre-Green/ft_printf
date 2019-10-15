/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:59:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 16:00:18 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H
# include "buff.h"

typedef struct		s_state
{
	t_buff			*buff;
	size_t			count;
	char			*frmt;
}					t_state;

void				clear_state(t_state *state);

#endif
