/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:05:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/10/17 14:24:19 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		main(void)
{
	test_static();
	test_fmt_char();
	test_fmt_str();
	test_fmt_ptr();
	test_fmt_int();
	test_fmt_hex();
	test_fmt_uint();
}
