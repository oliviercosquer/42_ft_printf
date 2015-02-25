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

int		ft_printf_print_o(t_param *param, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func		func;
	unsigned int		modifier;
	char				*str;
	int					nb_char;

	modifier = 0;
	nb_char = 0;
	if (!functions[0])
	{
		functions[0] = &ft_printf_print_long_octal;
		functions['l'] = &ft_printf_print_long_octal;
		functions['h'] = NULL;
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
		str = func(l);
		nb_char = ft_printf_get_flag_func(param->specifier)(param, str);
		ft_strdel(&str);
	}
	return (nb_char);
}

int		ft_printf_print_wstring(t_param *param, va_list *l)
{
	wchar_t	*str;
	wchar_t	c;
	int		nb_char;

	nb_char = 0;
	if (param->specifier == 'C')
	{
		nb_char++;
		c = va_arg(l, wchar_t);
		write(1, &c, 1);
	}
	else if (param->specifier == '%')
	{
		c = '%';
		write(1, &c, 1);
		nb_char++;
	}
	else
	{
		str = va_arg(*l, wchar_t *);
		if (str)
			ft_printf_putwstr(str);
		else
			ft_putstr(MSG_NULL_POINTER);
		nb_char += ft_printf_wstrlen(str);
	}
	return (nb_char);
}

int		ft_printf_print_octal(t_param *param, va_list *l)
{
	static t_print_func	functions[256];
	static t_print_func	functions2[256];
	t_print_func		func;
	char				*str;	
	int					nb_char;

	nb_char = 0;
	if (!functions[0])
	{
		functions[0] = &ft_printf_print_octal_default;
		functions['l'] = &ft_printf_print_long_octal;
		functions['h'] = NULL;
		functions2['l'] = &ft_printf_print_long_long_octal;
		functions2['h'] = NULL;
	}
	if (ft_strlen(param->specifier_length) == 2)
		func = functions2[(unsigned int)param->specifier_length[1]];
	else if (ft_strlen(param->specifier_length) == 1)
		func = functions[(unsigned int)param->specifier_length[0]];
	else
		func =  functions[0];
	if (func)
	{
		str = func(l);
		nb_char = ft_printf_get_flag_func(param->specifier)(param, str);
		ft_strdel(&str);
	}
	return (nb_char);
}

int		ft_printf_print_hex(t_param *param, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func		func;
	unsigned int		modifier;
	char				*str;
	int					nb_char;

	modifier = 0;
	nb_char = 0;
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
		str = func(l);
		if (param->specifier == 'X')
			ft_printf_str_toupper(&str);
		nb_char = ft_printf_get_flag_func(param->specifier)(param, str);
		ft_strdel(&str);
	}
	return (nb_char);
}
