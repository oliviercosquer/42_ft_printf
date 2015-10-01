/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 06:15:12 by olivier           #+#    #+#             */
/*   Updated: 2015/10/01 15:20:23 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_print_integer_default(va_list *list)
{
	char	*n_str;

	n_str = ft_itoa(va_arg(*list, int));
	return (n_str);
}

char	*ft_printf_print_long_integer(va_list *list)
{
	char	*n_str;

	n_str = ft_printf_lint_itoa(va_arg(*list, long int));
	return (n_str);
}

char	*ft_printf_print_long_long_integer(va_list *list)
{
	char	*n_str;

	n_str = NULL;
	n_str = ft_printf_long_lint_itoa(va_arg(*list, long long int));
	return (n_str);
}

char	*ft_printf_print_short_integer_default(va_list *list)
{
	char	*n_str;

	n_str = NULL;
	(void)list;
	ft_putstr("short integer");
	return (n_str);
}

char	*ft_printf_print_ushort_integer(va_list *list)
{
	char	*n_str;

	n_str = NULL;
	(void)list;
	ft_putstr("short u integer");
	return (n_str);
}
