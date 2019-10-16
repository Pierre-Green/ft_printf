/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:26:19 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/16 16:37:59 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

size_t						ft_strlen(const char *s);

void						ft_bzero(void *s, size_t n);

size_t						ft_count_digits(unsigned int n);

#endif
