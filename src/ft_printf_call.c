/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:12:38 by olivier           #+#    #+#             */
/*   Updated: 2015/02/20 08:27:44 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_print_integer(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func 		func;
	unsigned int		modifier;

	modifier = 0;
	if(!functions[0])
	{
		functions[0] = &ft_printf_print_integer_default;
		functions['l'] = &ft_printf_print_long_integer;
		functions['L'] = &ft_printf_print_long_long_integer;
		functions['h'] = &ft_printf_print_short_integer_default;
		functions['H'] = &ft_printf_print_ushort_integer;
	}
	if (param->specifier_length)
	{
		modifier = *(param->specifier_length);
		if (ft_strlen(param->specifier_length) == 2)
			modifier -= 32;
	}
	func = functions[modifier];
	func(param, total_char, l);
}

void	ft_printf_print_double(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func func;

	if(!functions['l'])
	{
	}
	func = functions[(int)*(param->specifier_length)];
	if (func)
		func(param, total_char, l);
	else
		ft_printf_print_double_default(param, total_char, l);
	(void)total_char;
}

void	ft_printf_print_string(t_param *param, int *total_char, va_list *l)
{
	char	*str;
	char	c;

	if (*(param->specifier) == 'c')
	{
		(*total_char)++;
		c = va_arg(l, int);
		write(1, &c, 1);
	}
	else
	{
		str = va_arg(*l, char *);
		*total_char += ft_strlen(str);
		ft_putstr(str);
	}
}

void	ft_printf_call(t_param *param, int *total_char, va_list *l)
{
	static t_call_func	*functions[256];
	t_call_func			*func;
	unsigned int		format;

	format = *(param->specifier);
	if (!functions['s'])
	{
		functions['s'] = &ft_printf_print_string;
		functions['c'] = &ft_printf_print_string;
		functions['d'] = &ft_printf_print_integer;
		functions['D'] = &ft_printf_print_integer;
		functions['i'] = &ft_printf_print_integer;
		functions['f'] = NULL;
	}
	func = functions[format];
	if (func)
	{
		func(param, total_char, l);
	}
}