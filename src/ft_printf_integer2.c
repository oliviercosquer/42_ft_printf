/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 00:46:33 by olivier           #+#    #+#             */
/*   Updated: 2015/10/01 15:21:34 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_print_integer_n(va_list *list)
{
	char	*n_str;
	int		*n;

	n_str = NULL;
	n = va_arg(*list, int *);
	(void)n;
	return (n_str);
}

char	*ft_printf_print_uinteger(va_list *list)
{
	char	*n_str;

	n_str = ft_printf_unsigned_itoa(va_arg(*list, unsigned int));
	return (n_str);
}

char	*ft_printf_print_long_uinteger(va_list *list)
{
	char	*n_str;

	n_str = ft_printf_ulong_itoa(va_arg(*list, unsigned long int));
	return (n_str);
}
