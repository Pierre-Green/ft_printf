/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:17:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/16 16:35:06 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_fmt_uint(void)
{
	printf_assert("uint fmt 1:", "|%u|", 42);
	printf_assert("uint fmt 2:", "|%.10u|", 42);
	printf_assert("uint fmt 3:", "|%010u|", 42);
	printf_assert("uint fmt 3:", "|%-10u|", 42);
	printf_assert("uint fmt 3:", "|%10u|", 42);
	printf_assert("uint fmt 3:", "|%15u|", UINT_MAX);
}
