/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/23 07:39:03 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <limits.h>

#ifdef _USER__
#	define PRINTF_MACRO ft_printf
#else
#	define PRINTF_MACRO ft_printf
#endif

#define THE_TEST "{%10d}", 42)
int	main(void)
{
	/*int lol;
	lol = printf("before %0*d after.ret:\n", 10, -4242);
	printf("ret: %d\n", lol);
	lol = 0;
	lol = ft_printf("before %0*d after.ret:\n", 10, -4242);
	printf("ret: %d\n", lol);
	return (0);*/
	#include "test.c"
	return (0);
}
