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

int		ft_printf_print_integer(t_param *param, va_list *l)
{
	t_print_func	func;
	char			*str;
	int				nb_char;

	str = NULL;
	nb_char = 0;
	func = ft_printf_get_call_integer(param->specifier_length);
	if (func)
	{
		str = func(l);
		nb_char += ft_printf_get_flag_func(param->specifier)(param, str);
		if (str)
			ft_strdel(&str);
	}
	return (nb_char);
}

int		ft_printf_print_unsigned_integer(t_param *param, va_list *l)
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
	str = func(l);
	//ft_strdel(&str);
	return (ft_printf_get_flag_func(param->specifier)(param, str));
}
/*
int		ft_printf_print_d(t_param *param, va_list *l)
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
		str = func(l);
		nb_char = ft_printf_get_flag_func(param->specifier)(param, str);
		ft_strdel(&str);
	}
	return (nb_char);
}*/

int		ft_printf_print_u(t_param *param, va_list *l)
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
		functions[0] = &ft_printf_print_long_uinteger;
		functions['l'] = &ft_printf_print_long_uinteger;
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
		nb_char += ft_printf_get_flag_func(param->specifier)(param, str);
		ft_strdel(&str);
	}
	return (nb_char);
}