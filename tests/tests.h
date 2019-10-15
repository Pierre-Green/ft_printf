/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:05:32 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 16:14:14 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "ft_printf.h"

void		printf_assert(char const *name, char const *format, ...);

void		test_static();

#endif
