/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:17:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/18 19:05:14 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_fmt_int(void)
{
	printf_assert("Int fmt 1:", "|%d|", 42);
	printf_assert("Int fmt 2:", "|%d|", -42);
	printf_assert("Int fmt 3:", "|%.5d|", 42);
	printf_assert("Int fmt 4:", "|%05d|", 42);
	printf_assert("Int fmt 5:", "|%-5d|", 42);
	printf_assert("Int fmt 6:", "|%d|", INT_MIN);
	printf_assert("Int fmt 7:", "|%15d|", INT_MIN);
	printf_assert("Int fmt 8:", "|%-15d|", INT_MIN);
	printf_assert("Int fmt 9:", "|%.15d|", INT_MIN);
	printf_assert("Int fmt 10:", "|%015d|", INT_MIN);
	printf_assert("Int fmt 11:", "|%d|", NULL);
}
