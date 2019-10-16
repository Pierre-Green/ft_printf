/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:18:19 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/16 16:18:47 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_fmt_hex(void)
{
	printf_assert("hex fmt 1:", "|%X|", 42);
	printf_assert("hex fmt 2:", "|%5x|", 42);
	printf_assert("hex fmt 3:", "|%.5X|", 42);
	printf_assert("hex fmt 4:", "|%05x|", 42);
	printf_assert("hex fmt 5:", "|%-5x|", 42);
}
