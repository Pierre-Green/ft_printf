/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:16:58 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/19 17:28:28 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_fmt_str(void)
{
	printf_assert("Str fmt 1", "|%s|", "rigolo");
	printf_assert("Str fmt 2", "|%10s|", "rigolo");
	printf_assert("Str fmt 3", "|%-10s|", "rigolo");
	printf_assert("Str fmt 4", "|%010s|", "rigolo");
	printf_assert("Str fmt 5", "|%.3s|", "rigolo");
	printf_assert("Str fmt 6", "|%10.3s|", "rigolo");
	printf_assert("Str fmt 7", "|%-10.3s|", "rigolo");
	printf_assert("Str fmt 8", "|%-10.15s|", "rigolo");
	printf_assert("Str fmt 9", "|%-10.15s|", "");
	printf_assert("Str fmt 10", "|%s|", NULL);
	printf_assert("Str fmt 11", "|%.2s|", NULL);
	printf_assert("Str fmt 12", "|%10s|", NULL);
	printf_assert("Str fmt 13", "|%-10s|", NULL);
	printf_assert("Str fmt 14", "|%.0s|", "sexy");
}
