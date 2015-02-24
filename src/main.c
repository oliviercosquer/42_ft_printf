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
#	define PRINTF_MACRO printf
#else
#	define PRINTF_MACRO printf
#endif

int	main(void)
{
	/*int ret;

	ret  = 0;
	ret = ft_printf("% Zoooo");
	printf("\nftret:%d\n", ret);*/
	//printf("d:%10.4d\n", 42);
	//ft_printf("d:%10.4d\n", 42);
	#include "test.c"
	return (0);
}
