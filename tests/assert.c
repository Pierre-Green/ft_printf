/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:07:22 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/15 16:18:35 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void			printf_assert(char const *name, char const *format, ...)
{
	va_list		args;

	va_start(args, format);
	printf("Starting `%s`:\n", name);
	ft_printf("Mine: ");
	ft_printf_va(format, args);
	printf("\n");
	va_end(args);
	va_start(args, format);
	printf("FBSD: ");
	vprintf(format, args);
	printf("\n\n");
	va_end(args);
}
