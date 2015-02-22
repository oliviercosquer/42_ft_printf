/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 04:20:01 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/22 04:20:02 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_print_d(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func		func;
	unsigned int		modifier;
	char				*str;

	modifier = 0;
	if (!functions[0])
	{
		functions[0] = &ft_printf_print_long_integer;
		functions['l'] = &ft_printf_print_long_integer;
		functions['L'] = &ft_printf_print_long_long_integer;
		functions['h'] = NULL;
		functions['H'] = NULL;
	}
	if (param->specifier_length)
	{
		modifier = *(param->specifier_length);
		if (ft_strlen(param->specifier_length) == 2)
			modifier -= 32;
	}
	func = functions[modifier];
	if (func)
	{
		str = func(total_char, l);
		ft_printf_flag_numeric(param, total_char, str);
		ft_putstr(str);
		ft_strdel(&str);
	}
}

void	ft_printf_print_o(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func		func;
	unsigned int		modifier;
	char				*str;

	modifier = 0;
	if (!functions[0])
	{
		functions[0] = &ft_printf_print_long_octal;
		functions['l'] = &ft_printf_print_long_octal;
		functions['L'] = &ft_printf_print_long_long_octal;
		functions['h'] = NULL;
		functions['H'] = NULL;
	}
	if (param->specifier_length)
	{
		modifier = *(param->specifier_length);
		if (ft_strlen(param->specifier_length) == 2)
			modifier -= 32;
	}
	func = functions[modifier];
	if (func)
	{
		str = func(total_char, l);
		ft_printf_flag_numeric(param, total_char, str);
		ft_putstr(str);
		ft_strdel(&str);
	}
}

void	ft_printf_print_wstring(t_param *param, int *total_char, va_list *l)
{
	wchar_t	*str;
	wchar_t	c;

	if (*(param->specifier) == 'C')
	{
		(*total_char)++;
		c = va_arg(l, wchar_t);
		write(1, &c, 1);
	}
	else if (*(param->specifier) == '%')
	{
		c = '%';
		write(1, &c, 1);
		(*total_char)++;
	}
	else
	{
		str = va_arg(*l, wchar_t *);
		if (str)
			ft_printf_putwstr(str);
		else
			ft_putstr(MSG_NULL_POINTER);
		*total_char += ft_printf_wstrlen(str);
	}
}

void	ft_printf_print_octal(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func		func;
	unsigned int		modifier;
	char				*str;

	modifier = 0;
	if (!functions[0])
	{
		functions[0] = &ft_printf_print_octal_default;
		functions['l'] = &ft_printf_print_long_octal;
		functions['L'] = &ft_printf_print_long_long_octal;
		functions['h'] = NULL;
		functions['H'] = NULL;
	}
	if (param->specifier_length)
	{
		modifier = *(param->specifier_length);
		if (ft_strlen(param->specifier_length) == 2)
			modifier -= 32;
	}
	func = functions[modifier];
	if (func)
	{
		str = func(total_char, l);
		ft_printf_flag_numeric(param, total_char, str);
		ft_putstr(str);
		ft_strdel(&str);
	}
}

void	ft_printf_print_hex(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func		func;
	unsigned int		modifier;
	char				*str;

	modifier = 0;
	if (!functions[0])
	{
		functions[0] = &ft_printf_print_hex_default;
		functions['l'] = &ft_printf_print_long_hex;
		functions['L'] = &ft_printf_print_long_long_hex;
		functions['h'] = &ft_printf_print_short_hex;
		functions['H'] = NULL;
	}
	if (param->specifier_length)
	{
		modifier = *(param->specifier_length);
		if (ft_strlen(param->specifier_length) == 2)
			modifier -= 32;
	}
	func = functions[modifier];
	if (func)
	{
		str = func(total_char, l);
		ft_printf_flag_numeric(param, total_char, str);
		if (*(param->specifier) == 'X')
			ft_printf_str_toupper(&str);
		ft_putstr(str);
		ft_strdel(&str);
	}
}
