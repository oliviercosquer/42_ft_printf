/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:12:38 by olivier           #+#    #+#             */
/*   Updated: 2015/02/20 05:39:28 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_printf_print_integer(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	*functions[256];
	static t_print_func *func;
	char				modifier;

	modifier = *(param->specifier_length);
	if(!functions['l'])
	{
		if (ft_strlen(param->specifier_length) == 2)
			modifier = *(param->specifier_length + 65);
		func = functions[(int)*(param->specifier_length)];
	}
	if (func)
		func(va_list *l);
	else
		ft_print_print_integer_default(l);
}

void	ft_printf_print_double(t_param *param, int *total_char, va_list *l)
{
	static t_print_func	*functions[256];
	static t_print_func *func;

	if(!functions['l'])
	{
	}
	func = functions[*(param->specifier_length)];
	if (func)
		func(va_list *l);
	else
		ft_print_print_double_default(l);
}

void	ft_printf_print_string(t_param *param, int *total_char, va_list *l)
{
	char	*str;
	char	c;

	if (param->specifier == 'c')
	{
		*total_char++;
		c = va_arg(l, int);
		write(1, &c, 1);
	}
	else
	{
		str = (char *)va_arg(l, char *);
		*total_char += ft_strlen(str);
	}
}

void	ft_printf_call(t_param *param, int *total_char, va_list *l)
{
	static t_call_func	*functions[256];
	t_call_func			*func;

	if (!functions['s'])
	{
		functions['s'] = &ft_printf_print_string;
		functions['c'] = &ft_printf_print_string;
		functions['d'] = &ft_printf_print_integer;
		functions['D'] = &ft_printf_print_integer;
		functions['i'] = &ft_printf_print_integer;
		functions['f'] = NULL;
	}
	func = functions[param->flag];
	if (func)
		*total_char += func(param, total_char, l);
}