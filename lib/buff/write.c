/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:26:00 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 18:13:54 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buff.h"

size_t			buff_write_char(t_buff *buff, char c)
{
	buff_flush_if_full(buff);
	buff->buff[buff->len] = c;
	buff->len++;
	buff_flush_if_full(buff);
	return (1);
}

size_t			buff_write_strl(t_buff *buff, char *s, size_t len)
{
	uint32_t	i;

	i = 0;
	while (i < len && buff->len != BUFF_SIZE)
	{
		buff->buff[buff->len] = *(s + i);
		buff->len++;
		i++;
	}
	if (buff->len == BUFF_SIZE)
	{
		buff_flush(buff);
		buff_write_strl(buff, s + i, len - i);
	}
	return (len);
}

size_t			buff_write_str(t_buff *buff, char *s)
{
	uint32_t	i;

	i = 0;
	while (s[i])
		i++;
	buff_write_strl(buff, s, i);
	return (i);
}
