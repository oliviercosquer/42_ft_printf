/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 00:46:33 by olivier           #+#    #+#             */
/*   Updated: 2015/02/23 07:38:05 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_print_integer_n(int *total_char, va_list *list)
{
	char	*n_str;
	int		*n;

	n_str = NULL;
	n = va_arg(list, int *);
	*n = *total_char;
	return (n_str);
}

char	*ft_printf_print_uinteger(int *total_char, va_list *list)
{
	char	*n_str;

	n_str = ft_printf_unsigned_itoa(va_arg(list, unsigned int));
	*total_char += ft_strlen(n_str);
	return (n_str);
}

char	*ft_printf_print_long_uinteger(int *total_char, va_list *list)
{
	char	*n_str;

	n_str = ft_printf_ulong_itoa(va_arg(list, unsigned long int));
	*total_char += ft_strlen(n_str);
	return (n_str);
}
