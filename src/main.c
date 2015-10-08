/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/10/08 18:42:22 by olivier          ###   ########.fr       */
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
	ft_printf("%s\n", "TROLOLO");
	return (0);
}
