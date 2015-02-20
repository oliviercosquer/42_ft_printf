/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/20 07:38:25 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_display_param(t_param *param)
{
	if (param)
	{
		printf("Flag:%c, Width:%s, Precision:%s, Specifier:%s, Length:%s\n",
			param->flag, param->width, param->precision, param->specifier,
			param->specifier_length);
	}
}
/*
int		ft_printf(const char *s, ...)
{
	va_list	list;
	t_param	*params;
	char	*str;
	int		nb_char;

	if (!*s)
		return (0);
	str = (char *)s;
	params = NULL;
	if (ft_strlen(str) >= 2)
		params = ft_printf_get_params(str);
	nb_char = 0;
	va_start(list, s);
	while (params)
	{
		ft_display_param(params);
		params->value = ft_printf_get_arg(&list, params);
		nb_char += ft_printf_string(&str, params);
		ft_printf_del_params(&params);
	}
	nb_char += ft_strlen(str);
	if (ft_strlen(str) > 0)
		write(1, str, ft_strlen(str));
	va_end(list);
	return (nb_char);
}*/

int		ft_printf(const char *s, ...)
{
	va_list	list;
	t_param	*param;
	char	*str;
	int		total_char;

	va_start(list, s);
	str = (char *)s;
	total_char = 0;
	while ((param = ft_printf_get_params(&str, &total_char)))
	{
		ft_printf_call(param, &total_char, &list);
		ft_printf_del_params(&param);
	}
	write(1, str, ft_strlen(str));
	return (total_char);
	va_end(list);
}