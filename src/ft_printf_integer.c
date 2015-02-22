/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 06:15:12 by olivier           #+#    #+#             */
/*   Updated: 2015/02/20 22:59:41 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_print_integer_default(int *total_char, va_list *list)
{
	char	*n_str;

	n_str = ft_itoa(va_arg(list, int));
	*total_char += ft_strlen(n_str);
	return (n_str);
}

char	*ft_printf_print_long_integer(int *total_char, va_list *list)
{
	char	*n_str;

	n_str = ft_printf_lint_itoa(va_arg(list, long int));
	*total_char += ft_strlen(n_str);
	return (n_str);
}

char	*ft_printf_print_long_long_integer(int *total_char, va_list *list)
{
	char	*n_str;

	n_str = NULL;
	n_str = ft_printf_long_lint_itoa(va_arg(list, long long int));
	*total_char += ft_strlen(n_str);
	return (n_str);
}

char	*ft_printf_print_short_integer_default(int *total_char, va_list *list)
{
	char	*n_str;

	n_str = NULL;
	(void)total_char;
	(void)list;
	ft_putstr("short integer");
	return (n_str);
}

char	*ft_printf_print_ushort_integer(int *total_char, va_list *list)
{
	char	*n_str;

	n_str = NULL;
	(void)total_char;
	(void)list;
	ft_putstr("short u integer");
	return (n_str);
}
