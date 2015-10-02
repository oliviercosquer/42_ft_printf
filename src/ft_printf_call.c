/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:12:38 by olivier           #+#    #+#             */
/*   Updated: 2015/10/02 14:22:12 by olivier          ###   ########.fr       */
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
	int		total_char;

	total_char = 0;
	str = NULL;
	if (param->specifier == 'c')
	{
		total_char += ft_printf_print_c(param, va_arg(*l, int));
	}
	else if (param->specifier == '%')
	{		
		total_char += ft_printf_print_c(param, '%');
	}
	else
	{
		str = va_arg(*l, char *);
		if (str)
			str = ft_strdup(str);
		else
			str = ft_strdup(MSG_NULL_POINTER);
		total_char += ft_printf_print_string_default(param, str);
	}
	return (total_char);
}

int	ft_printf_print_wchar_t(t_param *param, va_list *l)
{
	//wchar_t	*str;
	int		total_char;

	total_char = 0;
	//str = NULL;
	if (param->specifier == 'C')
	{
		total_char += ft_printf_print_wchar_c(param, va_arg(*l, wchar_t));
	}
	else if (param->specifier == '%')
	{		
		total_char += ft_printf_print_wchar_c(param, L'%');
	}
	else
	{
		/*str = va_arg(*l, wchar_t *);
		if (str)
			str = ft_strdup(str);
		else
			str = ft_strdup(MSG_NULL_POINTER);
		total_char += ft_printf_print_wchar_default(param, str);*/
	}
	return (total_char);
}

int	ft_printf_call(t_param *param, va_list *l)
{
	static t_call_func	functions[256];
	t_call_func			func;
	unsigned int		format;

	format = 0;
	if (param->specifier)
		format = param->specifier;
	if (!functions['s'])
	{
		functions[0] = NULL;
		functions['%'] = &ft_printf_print_string;
		functions['s'] = &ft_printf_print_string;
		functions['S'] = NULL;
		functions['p'] = &ft_printf_print_pointer;
		functions['d'] = &ft_printf_print_integer;
		//functions['D'] = &ft_printf_print_d;
		functions['i'] = &ft_printf_print_integer;
		functions['o'] = &ft_printf_print_octal;
		functions['O'] = &ft_printf_print_octal;
		functions['u'] = &ft_printf_print_unsigned_integer;
		//functions['U'] = &ft_printf_print_u;
		functions['x'] = &ft_printf_print_hex;
		functions['X'] = &ft_printf_print_hex;
		functions['c'] = &ft_printf_print_string;
		functions['C'] = ft_printf_print_wchar_t;
	}
	if (format)
		func = functions[format];
	//printf("f(u): %p\nfun: %p\n", &ft_printf_print_unsigned_integer, func);
	if (func)
		return (func(param, l));
	return (0);
}
