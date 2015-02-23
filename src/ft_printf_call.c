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

int	ft_printf_print_double(t_param *param, va_list *l)
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
		/*functions[0] = &ft_printf_print_double_default;
		functions['l'] = &ft_printf_print_long_double;*/
	}
	if (param->specifier_length)
		modifier = *(param->specifier_length);
	func = functions[modifier];
	(void)func;
	//str = func(l);
	(void)str;
	(void)l;
	//nb_char += ft_printf_flag_numeric(param, str);
	return (nb_char);
}

int	ft_printf_print_string(t_param *param, va_list *l)
{
	char	*str;
	char	c;
	int		total_char;

	total_char = 0;
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
		total_char = ft_printf_flag_string(param, str);
		ft_strdel(&str);
	}
	return (total_char);
}

int	ft_printf_call(t_param *param, va_list *l)
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
		return (func(param, l));
	return (0);
}
