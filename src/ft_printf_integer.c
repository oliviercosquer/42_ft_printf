/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 06:15:12 by olivier           #+#    #+#             */
/*   Updated: 2015/02/20 06:21:57 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_print_print_integer_default(t_param *param,
	int *total_char, va_list *list)
{
	char	*n_str;

	(void)param;
	n_str = ft_itoa(va_arg(list, int));
	*total_char += ft_strlen(n_str);
	ft_putstr(n_str);
	ft_strdel(&n_str);
}

void	ft_print_print_long_integer_default(t_param *param,
	int *total_char, va_list *list)
{
	(void)param;
	(void)total_char;
	(void)list;
}

void	ft_print_print_long_long_integer_default(t_param *param,
	int *total_char, va_list *list)
{
	(void)param;
	(void)total_char;
	(void)list;
}