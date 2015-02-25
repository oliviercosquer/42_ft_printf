/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/24 08:15:09 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <limits.h>

#ifdef _USER__
#	define PRINTF_MACRO ft_printf
#else
#	define PRINTF_MACRO ft_printf
#endif

int	main(void)
{
	int ret;

	ret  = 0;
	/*ret = ft_printf("% Zoooo");
	printf("\nftret:%d\n", ret);*/
	//printf("d:%10.4d\n", 42);
	//ft_printf("d:%10.4d\n", 42);
	ret = ft_printf("%O", 42);
	printf("\nftret:%d\n", ret);
	ret = printf("%O", 42);
	printf("\nftret:%d\n", ret);
	ret = ft_printf("%O", LONG_MAX);
	printf("\nftret:%d\n", ret);
	ret = printf("%O", LONG_MAX);
	printf("\nftret:%d\n", ret);
	//ft_printf("{%10d}", -42);
	//#include "test.c"
	return (0);
}
