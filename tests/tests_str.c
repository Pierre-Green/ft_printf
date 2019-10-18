/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:16:58 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/18 19:00:31 by pguthaus         ###   ########.fr       */
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
}
