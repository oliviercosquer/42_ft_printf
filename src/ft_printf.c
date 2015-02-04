/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/04 02:09:11 by olivier          ###   ########.fr       */
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

void	ft_printf_del_params(t_param **params)
{
	t_param	*tmp;

	tmp = *params;
	if (tmp->value)
		free(tmp->value);
	if (tmp->width)
		free(tmp->width);
	if (tmp->precision)
		free(tmp->precision);
	if (tmp->specifier)
		free(tmp->specifier);
	if (tmp->specifier_length)
		free(tmp->specifier_length);
	*params = tmp->next;
	free(tmp);
}

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
	if (ft_printf_strlen(str) > 2)
		params = ft_get_params(str);
	nb_char = 0;
	va_start(list, s);
	while (params)
	{
		params->value = ft_printf_get_arg(&list, params);
		nb_char += ft_printf_string(&str, params);
		ft_printf_del_params(&params);
	}
	nb_char += ft_printf_strlen(str);
	if (ft_printf_strlen(str) > 0)
		write(1, str, ft_printf_strlen(str));
	va_end(list);
	return (nb_char);
}

