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

int	main(void)
{
	//int ret;

	//ret  = 0;
	//ret = printf("aa%%bb");
	//printf("\nret:%d\n", ret);
	//ret = ft_printf("% Zoooo");
	//printf("\nftret:%d\n", ret);
	/*ret = printf("% Zoooo");
	printf("\nftret:%d\n", ret);*/
	#include "test.c"
	return (0);
}
