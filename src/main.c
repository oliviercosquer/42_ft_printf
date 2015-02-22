/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/21 23:06:52 by olivier          ###   ########.fr       */
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
	int	lol;

	printf("size lx:%ld\n", sizeof(unsigned long int));
	printf("size llx:%lld\n", sizeof(unsigned long long int));
	lol = printf("%  --d", -9999);
	printf("ret:%d\n", lol);
	lol = ft_printf("% d", -9999);
	printf("ret:%d\n", lol);	
	/*lol = printf("a%Ob%Oc%Od", 0, 55555, 100000);
	printf("ret:%d\n", lol);
	lol = ft_printf("a%Ob%Oc%Od", 0, 55555, 100000);
	printf("ret:%d\n", lol);*/
	return (0);
	#include "test.c"
	return (0);
}
