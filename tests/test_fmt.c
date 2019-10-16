/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:58:07 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/16 15:08:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void		test_fmt_char()
{
	printf_assert("Char fmt 1", "|%5c|", 'c');
	printf_assert("Char fmt 2", "|%-5c|", 'c');
	printf_assert("Char fmt 3", "|%-05c|", 'c');
	printf_assert("Char fmt 4", "|%0-5c|", 'c');
	printf_assert("Char fmt 5", "|%05c|", 'c');
	printf_assert("Char fmt 6", "|%00c|", 'c');
	printf_assert("Char fmt 7", "|%00c|", '\0');
}

static void		test_fmt_str()
{
	printf_assert("Str fmt 1", "|%s|", "rigolo");
	printf_assert("Str fmt 2", "|%10s|", "rigolo");
	printf_assert("Str fmt 3", "|%-10s|", "rigolo");
	printf_assert("Str fmt 4", "|%010s|", "rigolo");
	printf_assert("Str fmt 5", "|%.3s|", "rigolo");
	printf_assert("Str fmt 6", "|%10.3s|", "rigolo");
	printf_assert("Str fmt 7", "|%-10.3s|", "rigolo");
	printf_assert("Str fmt 8", "|%-10.15s|", "rigolo");
}

static void		test_fmt_int()
{
	printf_assert("Int fmt 1:", "|%d|", 42);
	printf_assert("Int fmt 2:", "|%d|", -42);
	printf_assert("Int fmt 3:", "|%.5d|", 42);
	printf_assert("Int fmt 4:", "|%05d|", 42);
	printf_assert("Int fmt 5:", "|%-5d|", 42);
	printf_assert("Int fmt 6:", "|%d|", INT_MIN);
	printf_assert("Int fmt 7:", "|%15d|", INT_MIN);
	printf_assert("Int fmt 7:", "|%-15d|", INT_MIN);
	printf_assert("Int fmt 7:", "|%.15d|", INT_MIN);
	printf_assert("Int fmt 7:", "|%015d|", INT_MIN);
}

void		test_fmt()
{
	// test_fmt_char();
	// test_fmt_str();
	test_fmt_int();
}
