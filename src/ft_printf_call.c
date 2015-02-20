/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:12:38 by olivier           #+#    #+#             */
/*   Updated: 2015/02/20 07:38:19 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_print_integer(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	functions[256];
	t_print_func 		func;
	int					modifier;

	modifier = *(param->specifier_length);
	if(!functions['l'])
	{
		if (ft_strlen(param->specifier_length) == 2)
			modifier = *(param->specifier_length + 65);
		func = functions[modifier];
	}
	if (func)
		func(param, total_char, l);
	else
		ft_print_print_integer_default(param, total_char, l);
	(void)total_char;
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
		ft_print_print_double_default(param, total_char, l);
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