/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:12:38 by olivier           #+#    #+#             */
/*   Updated: 2015/02/23 07:21:15 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_print_double(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func		func;
	unsigned int		modifier;
	char				*str;

	modifier = 0;
	if (!functions[0])
	{
		functions[0] = &ft_printf_print_double_default;
		functions['l'] = &ft_printf_print_long_double;
	}
	if (param->specifier_length)
		modifier = *(param->specifier_length);
	func = functions[modifier];
	str = func(total_char, l);
	//ft_printf_flag_numeric(param, total_char, str);
	(void)str;
}

void	ft_printf_print_string(t_param *param, int *total_char, va_list *l)
{
	char	*str;
	char	c;

	if (param->specifier == 'c')
	{
		c = va_arg(l, int);
		str = ft_strnew(1);
		if (str)
			str[0] = c;
	}
	else if (param->specifier == '%')
	{
		c = '%';
		str = ft_strnew(1);
		if (str)
			str[0] = c;
	}
	else
	{
		str = va_arg(*l, char *);
		if (str)
			str = ft_strdup(str);
		else
			str = ft_strdup(MSG_NULL_POINTER);
	}
	if (str)
	{
		*total_char += ft_strlen(str);
		ft_printf_flag_string(param, total_char, str);
		ft_strdel(&str);
	}
}

void	ft_printf_call(t_param *param, int *total_char, va_list *l)
{
	static t_call_func	functions[256];
	t_call_func			func;
	unsigned int		format;

	if (param->specifier)
		format = param->specifier;
	if (!functions['s'])
	{
		functions['s'] = &ft_printf_print_string;
		functions['S'] = NULL;
		functions['c'] = &ft_printf_print_string;
		functions['%'] = &ft_printf_print_string;
		functions['C'] = &ft_printf_print_wstring;
		functions['d'] = &ft_printf_print_integer;
		//functions['D'] = &ft_printf_print_d;
		functions['i'] = &ft_printf_print_integer;
		functions['o'] = &ft_printf_print_octal;
		//functions['O'] = &ft_printf_print_o;
		functions['u'] = &ft_printf_print_unsigned_integer;
		//functions['U'] = &ft_printf_print_u;
		functions['x'] = &ft_printf_print_hex;
		functions['X'] = &ft_printf_print_hex;
		functions['p'] = &ft_printf_print_pointer;
	}
	if (format)
		func = functions[format];
	if (func)
		func(param, total_char, l);
}
