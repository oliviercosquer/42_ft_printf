/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 02:51:56 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/23 06:27:32 by olivier          ###   ########.fr       */
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
	while ((param = ft_printf_get_params(&str, &total_char, &list)))
	{
		//ft_display_param(param);
		total_char += ft_printf_call(param, &list);
		ft_printf_del_params(&param);
	}
	ft_putstr(str);
	/*if (str)
		free(str);*/
	va_end(list);
	return (total_char);
}
