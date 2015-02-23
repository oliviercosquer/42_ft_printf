/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call_integer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 06:39:07 by olivier           #+#    #+#             */
/*   Updated: 2015/02/23 07:21:07 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_print_func	ft_printf_get_call_integer(char *specifier_length)
{
	static t_print_func	functions[256];
	static t_print_func	functions2[256];

	if (!functions[0])
	{
		functions[0] = &ft_printf_print_integer_default;
		functions['l'] = &ft_printf_print_long_integer;
		functions['h'] = &ft_printf_print_integer_default;
		functions['n'] = &ft_printf_print_integer_n;
		functions2['l'] = &ft_printf_print_long_long_integer;
		functions2['h'] = &ft_printf_print_ushort_integer;		
	}
	if (ft_strlen(specifier_length) == 2)
		return (functions2[(unsigned int)specifier_length[1]]);
	else if (ft_strlen(specifier_length) == 1)
		return (functions[(unsigned int)*specifier_length]);
	else
		return (functions[0]);
}

void	ft_printf_print_integer(t_param *param, int *total_char, va_list *l)
{
	t_print_func	func;
	char			*str;

	str = NULL;
	func = ft_printf_get_call_integer(param->specifier_length);
	if (func)
	{
		str = func(total_char, l);
		ft_printf_flag_numeric(param, total_char, str);
		if (str)
			ft_strdel(&str);
	}
}

void	ft_printf_print_unsigned_integer(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func		func;
	unsigned int		modifier;
	char				*str;

	modifier = 0;
	if (!functions[0])
	{
		functions[0] = &ft_printf_print_uinteger;
		functions['l'] = &ft_printf_print_long_uinteger;
	}
	if (param->specifier_length)
		modifier = *(param->specifier_length);
	func = functions[modifier];
	str = func(total_char, l);
	ft_printf_flag_numeric(param, total_char, str);
	ft_strdel(&str);
}