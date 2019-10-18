/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:01:22 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/18 19:04:51 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void		test_fmt_poly(void)
{
	printf_assert("Test poly 1", "|%d: %s; %c|", INT_MIN, "j'aime le cacao", 'z');
	printf_assert("Test poly 2", "|%5d: %-23s; %5c|", INT_MIN, "j'aime le cacao", 'z');
}
