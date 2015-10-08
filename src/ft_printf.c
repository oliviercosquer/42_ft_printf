/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/10/08 14:46:27 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_display_param(t_param *param)
{
	if (param)
	{
		printf("Flag:%s, Width:%s, Precision:%s, Specifier:%c, Length:%s\n",
			param->flag, param->width, param->precision, param->specifier,
			param->specifier_length);
	}
}

int		ft_printf(const char *s, ...)
{
	va_list	list;
	t_param	*param;
	char	*str;
	int		total_char;

	va_start(list, s);
	str = ft_strdup((char *)s);
	total_char = 0;
	while ((param = ft_printf_param_get(&str, &total_char, &list)))
	{
		setlocale(LC_ALL, "");
		if (DEBUG)
			ft_display_param(param);
		total_char += ft_printf_do(param, &list);
		ft_printf_del_params(&param);
	}
	ft_putstr(str);
	if (str)
		ft_strdel(&str);
	va_end(list);
	return (total_char);
}

int		ft_printf_do(t_param *param, va_list *list)
{
	t_convert_func	convert;
	char			*str;
	int				length;

	str = NULL;
	length = 0;
	convert = ft_printf_call_get_type_func(param);
	str = convert(list);

	/*
	* @TODO
	* flag
	* precision
	* width
	*/

	if (str)
	{
		ft_putstr(str);
		length = ft_strlen(str);
		ft_strdel(&str);
	}
	return (length);
}